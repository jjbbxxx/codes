import torch
from FederatedLearning import FederatedLearning


conf = {
        'model_name': 'CNN',
        'clients': 10,
        'epochs': 10,
        'local_epochs': 5,
        'batch_size': 32,
        'lr': 0.01,
    }


if __name__ == "__main__":
    torch.manual_seed(6)
    torch.cuda.manual_seed_all(6)

    fl = FederatedLearning('.', conf)
    fl.train('.')