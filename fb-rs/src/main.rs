//! file: main.rs
//! author: Jacob Xie
//! date: 2025/12/07 14:16:46 Sunday
//! brief:

mod monster_generated;

use flatbuffers::FlatBufferBuilder;
use monster_generated::fb_demo::sample::{Monster, MonsterArgs, Vec3, Vec3Args, root_as_monster};

fn main() {
    // Build buffer
    let mut builder = FlatBufferBuilder::new();

    let name = builder.create_string("Goblin");

    let pos_args = Vec3Args {
        x: 1.0,
        y: 2.0,
        z: 3.0,
    };
    let pos = Vec3::create(&mut builder, &pos_args);

    let monster_args = MonsterArgs {
        pos: Some(pos),
        hp: 150,
        name: Some(name),
    };
    let monster = Monster::create(&mut builder, &monster_args);

    builder.finish(monster, None);

    std::fs::write("monster.bin", builder.finished_data()).unwrap();

    // Read file
    let data = std::fs::read("monster.bin").unwrap();
    let monster = root_as_monster(&data).unwrap();

    println!("hp: {}", monster.hp());
    println!("name: {}", monster.name().unwrap());
    println!("pos.x: {}", monster.pos().unwrap().x());
}
