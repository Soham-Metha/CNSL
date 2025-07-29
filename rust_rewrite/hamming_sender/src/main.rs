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
    println!("\n┌─────┬──────────────┐");

    for ch in characters.chars() {
        println!("│  {}  │ ", if ch == '\n' { '\\' } else { ch });
        let ch = ch as u8;

        let code = get_code_for(&ch);
        out_f.write_all(&code.to_be_bytes()).unwrap();
    }

    println!("└─────┴──────────────┘");
    println!("\n\n================= SENDER =================\n\n");
}

fn get_code_for(ch: &u8) -> u16 {
    let mut bit_arr = [0; MESSAGE_SIZE + 1];
    let mut data_len = 0;

    (1..=MESSAGE_SIZE)
        .filter(|&i| !i.is_power_of_two())
        .for_each(|i| {
            let bit = (ch >> (DATA_SIZE - 1 - data_len)) & 1;
            bit_arr[i] = bit;
            data_len += 1;
        });
    0
}
