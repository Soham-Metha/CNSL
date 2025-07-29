use std::env;
use std::fs;
use std::process;

struct HammingSymbol {
    char_val: u8,
    encoded_val: u16,
}

fn get_files(args: &[String]) -> (String, String) {
    // println!("All args: {:?}", args);

    if args.len() < 3 {
        eprintln!("Usage: {} <in_file_name> <in_file_name>", args[0]);
        process::exit(1);
    }

    let in_file = fs::read_to_string(&args[1]).expect("CANT OPEN IN FILE");
    let out_file = fs::read_to_string(&args[2]).expect("CANT OPEN OUT FILE");

    println!("\nIN : {}\nOUT: {}\n", args[1], args[2]);

    (in_file, out_file)
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let out: [HammingSymbol; 100];

    println!("\n================= SENDER =================\n");
    let (in_f, out_f) = get_files(&args);

    for ch in in_f.chars() {}

    println!("\n┌─────┬──────────────┐\n");
    println!("└─────┴──────────────┘");
    println!("\n\n================= SENDER =================\n\n");
}
