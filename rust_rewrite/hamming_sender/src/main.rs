use std::env;
use std::fs;
use std::io::Read;
use std::io::Write;
use std::process;

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
        out_f.write_all(&code.encoded_val.to_be_bytes()).unwrap();
    }

    println!("└─────┴──────────────┘");
    println!("\n\n================= SENDER =================\n\n");
}
