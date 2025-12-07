# @file:	main.py
# @author:	Jacob Xie
# @date:	2025/12/07 14:17:45 Sunday
# @brief:


import flatbuffers
from FbDemo.Sample import Monster, Vec3

# Build buffer
builder = flatbuffers.Builder(1024)

name = builder.CreateString("Goblin")

Vec3.Vec3Start(builder)
Vec3.Vec3AddX(builder, 1.0)
Vec3.Vec3AddY(builder, 2.0)
Vec3.Vec3AddZ(builder, 3.0)
pos = Vec3.Vec3End(builder)

Monster.MonsterStart(builder)
Monster.MonsterAddPos(builder, pos)
Monster.MonsterAddHp(builder, 150)
Monster.MonsterAddName(builder, name)
monster = Monster.MonsterEnd(builder)

builder.Finish(monster)
buf = builder.Output()

with open("monster.bin", "wb") as f:
    f.write(buf)

# Read & access
data = open("monster.bin", "rb").read()
monster = Monster.Monster.GetRootAsMonster(data, 0)

print("hp:", monster.Hp())
print("name:", monster.Name().decode())
print("pos.z:", monster.Pos().Z())
