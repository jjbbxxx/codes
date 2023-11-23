import random
import torch
import torch.nn.functional as F
from typing import Tuple
from torch.utils.data import DataLoader
from Model import get_model


class Server:

    def __init__(self, test_data_loader: DataLoader, model_name: str):
        self._device = torch.device('cpu')
        # 全局模型
        self._global_model = get_model(model_name).to(self._device)
        # 验证测试集
        self._test_data_loader = test_data_loader
        # 累积器
        self._accumulator = dict()
        # 数量
        self._total_number = 0

    # 返回准确率和平均损失
    def eval(self) -> Tuple[float, float]:
        total_loss = 0.0
        correct = 0
        data_size = 0

    #    raise NotImplementedError("实现模型测试的功能")
    # ======================================

    # 总个数
        data_size = 0
    # 模型切换到预测模式
        self._global_model.eval()
        for data, label in self._test_data_loader:
            data_size += data.size()[0]
        # 计算结果
            output = self._global_model(data)
    # 计算损失
            total_loss += F.cross_entropy(output, label, reduction='sum').item()
    # 统计正确个数
            _, pred = output.max(dim=1)
            correct += pred.eq(label.data.view_as(pred)).cpu().sum().item()
    
    # ======================================

        acc = 100.0 * (float(correct)/data_size)
        loss = total_loss/data_size
        return acc, loss

    # 聚合之前，先准备累加器
    def before_aggregate(self) -> None:
        self._accumulator.clear()
        self._total_number = 0
        for name, param in self._global_model.state_dict().items():
            self._accumulator[name] = torch.zeros_like(param)

    # 聚合进去，即累加
    def aggregate(self, num: int, update: dict) -> None:
        self._total_number += num 
        for k,v in update.items():
            self._accumulator[k].add_(v)
    #   raise NotImplementedError("实现梯度更新的聚合过程")

    # 更新全局模型
    def update_model(self):
        for k,v in self._global_model.state_dict().items():
            hhh = self._accumulator[k]/self._total_number
            v.add_(hhh)
    #   raise NotImplementedError("实现更新全局模型的过程")

    # 获取模型参数
    def get_global_parameters(self) -> dict:
        return self._global_model.state_dict()
