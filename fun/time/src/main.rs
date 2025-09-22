use std::env;
use std::fs::File;
use std::io::{self, BufRead, Write};

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

fn timeConversion(s: &str) -> String {
    let h: u32 = s[0..2].parse().unwrap();
    let m: u32 = s[3..5].parse().unwrap();
    let sec: u32 = s[6..8].parse().unwrap();
    let is_pm = &s[8..10] == "PM";

    let h24 = (h % 12) + if is_pm { 12 } else { 0 };

    format!("{:02}:{:02}:{:02}", h24, m, sec)
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();

    let s = stdin_iterator.next().unwrap().unwrap();

    let result = timeConversion(&s);

    writeln!(&mut fptr, "{}", result).ok();
}

