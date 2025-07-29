use std::env;
use std::fs;

fn get_files(args: Vec<String>) {
    // println!("All args: {:?}", args);

    if args.len() < 3 {
        eprintln!("Usage: {} <in_file_name> <in_file_name>", args[0]);
        return;
    }

    let in_file = fs::read(&args[1]).expect("CANT OPEN IN FILE");
    let out_file = fs::read(&args[2]).expect("CANT OPEN OUT FILE");
    println!("\nIN : {}\nOUT: {}\n", args[1], args[2]);
}

fn main() {
    let args = env::args().collect();
    println!("\n================= SENDER =================\n");
    get_files(args);

    println!("\n┌─────┬──────────────┐\n");
    println!("└─────┴──────────────┘");
    println!("\n\n================= SENDER =================\n\n");
}
