use std::env;
use std::fs;
use std::fs::File;
use std::fs::OpenOptions;
use std::io::Write;
use std::process;

struct HammingSymbol {
    char_val: u8,
    encoded_val: u16,
}

fn get_files(args: &[String]) -> (String, File) {
    // println!("All args: {:?}", args);

    if args.len() < 3 {
        eprintln!("Usage: {} <in_file_name> <in_file_name>", args[0]);
        process::exit(1);
    }

    let in_file = fs::read_to_string(&args[1]).expect("CANT OPEN IN FILE");
    let out_file = OpenOptions::new()
        .write(true)
        .create(true)
        .truncate(true)
        .open(&args[1])
        .expect("CANT OPEN OUT FILE");

    println!("\nIN : {}\nOUT: {}\n", args[1], args[2]);

    (in_file, out_file)
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let out: [HammingSymbol; 100];

    println!("\n================= SENDER =================\n");
    let (in_f, mut out_f) = get_files(&args);

    for ch in in_f.chars() {}

    for symbol in &out {
        out_f.write_all(&symbol.encoded_val.to_be_bytes());
    }

    println!("\n┌─────┬──────────────┐\n");
    println!("└─────┴──────────────┘");
    println!("\n\n================= SENDER =================\n\n");
}
