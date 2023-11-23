import os
import json
import torchvision as tv
import torchvision.transforms as tfs
from torch.utils.data import DataLoader
from torch.utils.data.sampler import SubsetRandomSampler
from Server import Server
from Client import Client


class FederatedLearning:

    def __init__(self, path: str, conf: dict):
        print("载入测试数据集")
        print("初始化服务器")
        test_ds = tv.datasets.MNIST(path, train=False, download=True, transform=tfs.ToTensor())
        test_data_loader = DataLoader(test_ds, batch_size=32, shuffle=True)
        self._sever = Server(test_data_loader, conf['model_name'])

        print("载入训练数据集")
        print("初始化参与方")
        train_ds = tv.datasets.MNIST(path, train=True, download=True, transform=tfs.ToTensor())
        client_number = conf['clients']
        client_conf = dict()
        client_conf['epochs'] = conf['local_epochs']
        client_conf['lr'] = conf['lr']
        client_conf['model_name'] = conf['model_name']
        self._clients = list()
        # 所有数据的索引的列表
        indices = list(range(len(train_ds)))
        # 每个客户端拥有的数据长度
        data_len = int(len(train_ds)/client_number)
        for i in range(client_number):
            # 通过截取相应长度的数据集给客户端模拟每个客户端拥有的数据
            client_data_loader = DataLoader(train_ds, batch_size=conf['batch_size'],
                                            sampler=SubsetRandomSampler(indices[i*data_len: (i+1)*data_len]))
            self._clients.append(Client(client_conf, client_data_loader, data_len, i))

        self._global_epochs = conf['epochs']

    def train(self, save_path: str = '.') -> None:
        accs = list()
        losses = list()
        acc, loss = self._sever.eval()
        accs.append(acc)
        losses.append(loss)
        print("Init model, acc: %.2f, loss: %.2f" % (acc, loss))
        for e in range(self._global_epochs):
            self._sever.before_aggregate()
            for client in self._clients:
                # 下载最新模型
                latest_model = self._sever.get_global_parameters()
            #    raise NotImplementedError("获取最新模型")

                # 客户端进行本地训练，并发送训练结果
                updates = client.get_updates(latest_model)
            #   raise NotImplementedError("进行本地训练，获取更新梯度")

                # 客户端发送数量
                num = client.get_num()
            #   raise NotImplementedError("获取数量")

                # 聚合结果
                self._sever.aggregate(num, updates)
            #   raise NotImplementedError("进行聚合")

            # 更新全局模型
        #   raise NotImplementedError("更新全局模型")
            self._sever.update_model()
            acc, loss = self._sever.eval()
            accs.append(acc)
            losses.append(loss)
            print("Epoch %d, acc: %.2f, loss: %.2f" % (e+1, acc, loss))
        # 通过json保存文件，在show——chart文件里面可以载入进入，实现图表
        with open(os.path.join(save_path, "avg.acc"), 'w') as f:
            json.dump(accs, f)
        with open(os.path.join(save_path, 'avg.ls'), 'w') as f:
            json.dump(losses, f)
