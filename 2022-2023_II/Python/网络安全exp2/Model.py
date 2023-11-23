import torch
import torch.nn.functional as F
from torchvision.models import vgg13


class NNNet(torch.nn.Module):

    def __init__(self):
        super(NNNet, self).__init__()
        self.fc1 = torch.nn.Linear(28*28, 1024)
        self.fc2 = torch.nn.Linear(1024, 256)
        self.fc3 = torch.nn.Linear(256, 10)

    def forward(self, x: torch.Tensor):
        x = x.view(-1, 28*28)
        x = self.fc1(x)
        x = F.relu(x)
        x = self.fc2(x)
        x = F.relu(x)
        return self.fc3(x)


class CNNNet(torch.nn.Module):

    def __init__(self):
        super(CNNNet, self).__init__()
        self.model = torch.nn.Sequential(
            # The size of the picture is 28x28
            torch.nn.Conv2d(in_channels=1, out_channels=16, kernel_size=3, stride=1, padding=1),
            torch.nn.ReLU(),
            torch.nn.MaxPool2d(kernel_size=2, stride=2),

            # The size of the picture is 14x14
            torch.nn.Conv2d(in_channels=16, out_channels=32, kernel_size=3, stride=1, padding=1),
            torch.nn.ReLU(),
            torch.nn.MaxPool2d(kernel_size=2, stride=2),

            # The size of the picture is 7x7
            torch.nn.Conv2d(in_channels=32, out_channels=64, kernel_size=3, stride=1, padding=1),
            torch.nn.ReLU(),

            torch.nn.Flatten(),
            torch.nn.Linear(in_features=7 * 7 * 64, out_features=128),
            torch.nn.ReLU(),
            torch.nn.Linear(in_features=128, out_features=10),
            torch.nn.Softmax(dim=1)
        )

    def forward(self, input):
        output = self.model(input)
        return output


def get_model(name: str):
    if name == 'NN':
        return NNNet()
    elif name == 'CNN':
        return CNNNet()


if __name__ == "__main__":
    model = vgg13(pretrained=True)
    # print(model)
    state_dict = model.state_dict()
    for k, v in state_dict.items():
        print(k, v.shape)
