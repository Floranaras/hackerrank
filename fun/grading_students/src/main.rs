use std::env;
use std::fs::File;
use std::io::{self, BufRead, Write};

fn gradingStudents(grades: &[i32]) -> Vec<i32> {
    grades
        .iter()
        .map(|&g| {
            if g < 38 { 
                g 
            } else {
                let rem = g % 5;
                if rem >= 3 { g + (5 - rem) } else { g }
            }
        })
        .collect()
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();
    let grades_count = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

    let grades: Vec<i32> = (0..grades_count)
        .map(|_| stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap())
        .collect();

    for result in gradingStudents(&grades) {
        writeln!(&mut fptr, "{}", result).ok();
    }
}

