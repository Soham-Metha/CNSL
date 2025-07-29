use std::env;

fn get_files(args: Vec<String>) {
    println!("All args: {:?}", args);

    if args.len() < 3 {
        eprintln!("Usage: {} <in_file_name> <in_file_name>", args[0]);
        return;
    }

    let in_file_name = &args[1];
    let out_file_name: &String = &args[2];
    println!("\nIN : {}\nOUT: {}\n", in_file_name, out_file_name);
}

fn main() {
    let args = env::args().collect();
    println!("\n================= SENDER =================\n");
    get_files(args);

    println!("\n┌─────┬──────────────┐\n");
    println!("└─────┴──────────────┘");
    println!("\n\n================= SENDER =================\n\n");
}
