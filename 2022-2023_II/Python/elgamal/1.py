import random
# 密钥生成
def generate_keys(p, g):
    x = random.randint(1, p - 1)  # 私钥
    y = pow(g, x, p)  # 公钥
    return x, y

# 加密
def encrypt(p, g, y, M):
    k = random.randint(1, p - 1)  # 加密密钥
    C1 = pow(g, k, p)
    C2 = (M * pow(y, k, p)) % p
    return C1, C2

# 解密
def decrypt(p, x, C1, C2):
    inv = pow(C1, x, p)  # C1^x mod p的逆元
    M = (C2 * inv) % p
    return M

# 测试代码
p = 23  # 大素数
g = 5   # 生成元

# 密钥生成
x, y = generate_keys(p, g)
print("公钥:", y)
print("私钥:", x)

# 明文消息
M = 9

# 加密
C1, C2 = encrypt(p, g, y, M)
print("密文:", C1, C2)

# 解密
decrypted_M = decrypt(p, x, C1, C2)
print("解密后的明文:", decrypted_M)