use std::env;
use std::fs;
use std::process;

fn get_files(args: Vec<String>) -> (Vec<u8>, Vec<u8>) {
    // println!("All args: {:?}", args);

    if args.len() < 3 {
        eprintln!("Usage: {} <in_file_name> <in_file_name>", args[0]);
        process::exit(1);
    }

    let in_file = fs::read(&args[1]).expect("CANT OPEN IN FILE");
    let out_file = fs::read(&args[2]).expect("CANT OPEN OUT FILE");

    println!("\nIN : {}\nOUT: {}\n", args[1], args[2]);

    (in_file, out_file)
}

fn main() {
    let args = env::args().collect();
    println!("\n================= SENDER =================\n");
    get_files(args);

    println!("\n┌─────┬──────────────┐\n");
    println!("└─────┴──────────────┘");
    println!("\n\n================= SENDER =================\n\n");
}
