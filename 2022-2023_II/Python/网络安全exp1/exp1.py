import torch
import torchvision
import torchvision.transforms as tfs
import torch.nn.functional as F
from torch.nn import Module
from torch.utils.data import DataLoader
import matplotlib.pyplot as plt
import time

class NNNet(Module):
    def __init__(self):
        super(NNNet,self).__init__()
        self.fc1 = torch.nn.Linear(28*28,1024)
        self.fc2 = torch.nn.Linear(1024,256)
        self.fc3 = torch.nn.Linear(256,10)

    def forward(self, x: torch.Tensor):
        x = x.view(-1, 28 * 28)
        x = self.fc1(x)
        x = F.relu(x)
        x = self.fc2(x)
        x = F.relu(x)
        return self.fc3(x)

def test_model(model, data_loader):
# 正确个数
    correct = 0
# 总损失
    total_loss = 0.0
# 总个数
    cnt = 0
# 模型切换到预测模式
    model.eval()
    for data, label in data_loader:
        cnt += data.size()[0]
    # 计算结果
        output = model(data)
# 计算损失
        total_loss += F.cross_entropy(output, label, reduction='sum')
# 统计正确个数
        _, pred = output.max(dim=1)
        correct += pred.eq(label.data.view_as(pred)).cpu().sum().item()
# 计算正确率和平均损失
    acc = 100.0 * correct / cnt
    loss = total_loss / cnt
    return acc, loss
def show_acc_chart(accs):
    x = range(len(accs))
    plt.plot(x, accs, color="blue")
    plt.xlabel("Epochs")
    plt.ylabel("Accuracy")
    plt.legend(["FedAvg"], loc="upper left")
    plt.title('Accuracy of FedAvg')
    plt.show()
if __name__ == '__main__':
    my_device = torch.device('cpu')
    train_dataset = torchvision.datasets.MNIST(root='.', train=True, download=True,
                                               transform=tfs.ToTensor())
    test_dataset = torchvision.datasets.MNIST(root='.', train=False, download=True,
                                              transform=tfs.ToTensor())
    batch_size = 32
    train_data_loader = DataLoader(dataset=train_dataset, batch_size=batch_size,
                                   shuffle=True)
    test_data_loader = DataLoader(dataset=test_dataset, batch_size=batch_size,
                                  shuffle=True)
    # 迭代次数
    epochs = 10
    # 学习率
    lr = 0.001
    # 初始化模型，并载入CPU中
    nn = NNNet().to(my_device)
    # 设置优化方法，随机梯度下降法（sGD）
    optimizer = torch.optim.SGD(nn.parameters(), lr=lr)
    # 记录准确率和损失的列表
    accs = list()
    losses = list()
    # 测试初始化的模型的准确率，以及损失
    acc, loss = test_model(nn, test_data_loader)
    print("Initial model, accuracy: %.2f, loss: %.2f" % (acc, loss))
    accs.append(acc)
    losses.append(loss)
    for e in range(epochs):
        # 切换到训练模式
        nn.train()

        for data, label in train_data_loader:
            output = nn(data)
            loss = F.cross_entropy(output, label)
            optimizer.zero_grad()
            loss.backward()
            optimizer.step()
        print("Epoch %d done" % (e + 1))
        acc, loss = test_model(nn, test_data_loader)
        print("Epoch %d, accuracy: %.2f, loss: %.2f" % (e + 1, acc, loss))
    # 放到列表中
        accs.append(acc)
        losses.append(loss)

    show_acc_chart(accs)
