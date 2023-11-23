import json
import torchvision
import torchvision.transforms as tfs
import matplotlib.pyplot as plt
from torch.utils.data import DataLoader


# 显示数据集的一些图片
def show_picture():
    dataset = torchvision.datasets.MNIST(root='.', train=True, transform=tfs.ToTensor(), download=True)
    data_loader = DataLoader(dataset=dataset, batch_size=32, shuffle=True)
    data, label = next(iter(data_loader))
    print(data.shape)
    print(label.shape)
    plt.figure(figsize=(10, 10), dpi=100)
    for i in range(9):
        plt.subplot(3, 3, i+1)
        plt.imshow(data[i][0], cmap='gray')
        plt.title("Label: {}".format(label[i]))
    plt.show()


# 准确率折线图
def show_acc_chart(path: str):
    with open(path, 'r') as f:
        accs = json.load(f)
    x = range(len(accs))
    plt.plot(x, accs, color="blue")
    plt.xlabel("Epochs")
    plt.ylabel("Accuracy")
    # x轴和y轴的显示范围
    plt.xticks(range(len(accs)))
    plt.yticks(range(0, 110, 10))
    plt.legend(["FedAvg"], loc="upper left")
    plt.title('Accuracy of FedAvg')
    plt.show()


# 注意改变y轴的显示范围，或者不加yticks也可以
def show_loss_chart(path: str):
    with open(path, 'r') as f:
        losses = json.load(f)
    x = range(len(losses))
    plt.plot(x, losses, color="blue")
    plt.xlabel("Epochs")
    plt.ylabel("Accuracy")
    # x轴和y轴的显示范围
    plt.xticks(range(len(losses)))
    plt.yticks(range(0, 110, 10))
    plt.legend(["FedAvg"], loc="upper left")
    plt.title('Loss of FedAvg')
    plt.show()
#   raise NotImplementedError("完成显示Loss折线图函数！")


if __name__ == '__main__':
    show_picture()
    show_acc_chart('avg.acc')
    show_loss_chart('avg.ls')
