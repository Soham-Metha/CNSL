use std::env;
use std::fs;
use std::io::Read;
use std::io::Write;
use std::process;

const DATA_SIZE: usize = 8;
const PARITY_SIZE: usize = 4;
const MESSAGE_SIZE: usize = DATA_SIZE + PARITY_SIZE;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 3 {
        process::exit(1);
    }
    let mut out_f = fs::File::create(&args[2]).unwrap();

    let mut in_f = fs::File::open(&args[1]).unwrap();
    let mut characters = String::new();
    in_f.read_to_string(&mut characters).unwrap();

    println!("\n================= SENDER =================\n");
    println!("\nIN : {}\nOUT: {}\n", args[1], args[2]);
    println!("\n================= SENDER =================\n");
    println!("\n┌─────┬──────────────┐\n");

    for ch in characters.chars() {
        let ch = ch as u8;

        println!("│  {}  │ ", if ch == b'\n' { b'\\' } else { ch });

        let code = getCodeFor(&ch);
        out_f.write_all(&code.to_be_bytes()).unwrap();
    }

    println!("└─────┴──────────────┘");
    println!("\n\n================= SENDER =================\n\n");
}

fn getCodeFor(ch: &u8) -> u16 {
    let mut bitArr = [0; MESSAGE_SIZE];
    let mut dataLen = DATA_SIZE;
    let mut pow_of_2 = 1;
    for i in (1..=MESSAGE_SIZE).rev() {
        if i == pow_of_2 {
            pow_of_2 = pow_of_2 << 1;
        } else {
            bitArr[i] = if (ch & (1 << (dataLen - 1))) != 0 {
                1
            } else {
                0
            };
            dataLen -= 1;
        }
    }
    10
}
