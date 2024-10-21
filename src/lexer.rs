#[derive(Debug, PartialEq)]
enum Token {
    Let,
    Identifier(String),
    Number(i64),
    Equal,
    Plus,
    Semicolon,
    Eof,
}

struct Lexer {
    input: String,
    position: usize,
}

impl Lexer {
    fn new(input: String) -> Self {
        Self { input, position: 0 }
    }

    fn next_token(&mut self) -> Token {
        self.skip_whitespace();
        if self.position >= self.input.len() {
            return Token::Eof;
        }

        let ch = self.current_char();
        let token = match ch {
            '=' => Token::Equal,
            '+' => Token::Plus,
            ';' => Token::Semicolon,
            '0'..='9' => {
                let number = self.read_number();
                Token::Number(number)
            }
            'a'..='z' | 'A'..='Z' => {
                let identifier = self.read_identifier();
                if identifier == "let" {
                    Token::Let
                } else {
                    Token::Identifier(identifier)
                }
            }
            _ => panic!("Unknown character: {}", ch),
        };

        self.position += 1;
        token
    }

    fn current_char(&self) -> char {
        self.input.chars().nth(self.position).unwrap_or('\0')
    }

    fn skip_whitespace(&mut self) {
        while let Some(ch) = self.input.chars().nth(self.position) {
            if !ch.is_whitespace() {
                break;
            }
            self.position += 1;
        }
    }

    fn read_number(&mut self) -> i64 {
        let start = self.position;
        while let Some(ch) = self.input.chars().nth(self.position) {
            if !ch.is_numeric() {
                break;
            }
            self.position += 1;
        }
        self.input[start..self.position].parse().unwrap()
    }

    fn read_identifier(&mut self) -> String {
        let start = self.position;
        while let Some(ch) = self.input.chars().nth(self.position) {
            if ch.is_alphabetic() {
                self.position += 1;
            } else {
                break;
            }
        }
        self.input[start..self.position].to_string()
    }
}
