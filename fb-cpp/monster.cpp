/**
 * @file:	monster.cpp
 * @author:	Jacob Xie
 * @date:	2025/12/07 13:26:24 Sunday
 * @brief:
 **/

#include "monster_generated.h"
#include <fstream>
#include <iostream>

using namespace FbDemo::Sample;

int main() {
  // Build buffer
  flatbuffers::FlatBufferBuilder builder;

  auto name = builder.CreateString("Goblin");
  auto pos = FbDemo::Sample::CreateVec3(builder, 1.0f, 2.0f, 3.0f);
  auto monster = FbDemo::Sample::CreateMonster(builder, pos, 150, name);

  builder.Finish(monster);

  // Write file
  std::ofstream ofs("monster.bin", std::ios::binary);
  ofs.write(reinterpret_cast<const char *>(builder.GetBufferPointer()),
            builder.GetSize());
  ofs.close();

  // Read file
  std::ifstream ifs("monster.bin", std::ios::binary);
  std::vector<uint8_t> data((std::istreambuf_iterator<char>(ifs)),
                            std::istreambuf_iterator<char>());

  auto read_monster = FbDemo::Sample::GetMonster(data.data());

  std::cout << "hp: " << read_monster->hp() << "\n";
  std::cout << "name: " << read_monster->name()->str() << "\n";
  std::cout << "pos.y: " << read_monster->pos()->y() << "\n";

  return 0;
}
