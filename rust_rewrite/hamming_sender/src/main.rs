use std::env;
use std::fs;
use std::io::Read;
use std::io::Write;
use std::process;

struct HammingSymbol {
    char_val: u8,
    encoded_val: u16,
}

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 3 {
        process::exit(1);
    }
    let mut out_f = fs::File::create(&args[2]).unwrap();

    let mut in_f = fs::File::open(&args[1]).unwrap();
    let mut characters = String::new();
    in_f.read_to_string(&mut characters);

    let mut out: [HammingSymbol; 100];

    println!("\n================= SENDER =================\n");
    println!("\nIN : {}\nOUT: {}\n", args[1], args[2]);
    println!("\n================= SENDER =================\n");

    for (i, ch) in characters.chars().enumerate() {
        let ch = ch as u8;
        out[i] = HammingSymbol {
            char_val: ch,
            encoded_val: 0,
        }
    }

    for symbol in &out {
        out_f.write_all(&symbol.encoded_val.to_be_bytes()).unwrap();
    }

    println!("\n┌─────┬──────────────┐\n");
    println!("└─────┴──────────────┘");
    println!("\n\n================= SENDER =================\n\n");
}
