import torch
import torch.nn.functional as F
from torch.utils.data import DataLoader
from Model import get_model


class Client:

    def __init__(self, conf: dict, data_loader: DataLoader, num: int, index: int):
        self._device = torch.device('cpu')
        self._conf = conf
        self._data_loader = data_loader
        self._index = index
        self._num = num

    def local_train(self, model_parameters: dict, epochs: int, lr: float) -> dict:
        model = get_model(self._conf['model_name']).to(self._device)
        for name, param in model_parameters.items():
            model.state_dict()[name].copy_(param.clone())

        optimizer = torch.optim.SGD(model.parameters(), lr=lr)
        model.train()
        for e in range(epochs):
            # 切换到训练模式
            for data, label in self._data_loader:
                # 前向传播
                output = model(data)
                # 计算损失
                loss = F.cross_entropy(output, label)
                # 先清理梯度，因为优化器会记录梯度，先清理
                optimizer.zero_grad()
                # 反向传播
                loss.backward()
                # 更新梯度
                optimizer.step()
            print("Epoch %d done" % (e + 1))
        #   raise NotImplementedError("实现本地训练的过程。")

        diff = dict()
        for name, param in model.state_dict().items():
            diff[name] = (param - model_parameters[name])*self._num
        print("{} local train done".format(self.get_name()))
        return diff

    def get_name(self) -> str:
        return "Client " + str(self._index)

    def get_updates(self, global_model_parameters: dict) -> dict:
        # 进行本地训练
        return self.local_train(global_model_parameters, self._conf['epochs'],
                                self._conf['lr'])

    def get_num(self):
        return self._num
