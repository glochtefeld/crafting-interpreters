package com.gavinlochtefeld.lox;
import java.util.*; // ArrayList, HashMap, List, Map
import java.lang.*; // Math

class Scanner {
    private final String source;
    private final List<Token> tokens = new ArrayList<>();
    private static final Map<String, TokenType> keywords;
    static {
        keywords = new HashMap<>();
        keywords.put("and",     TokenType.AND);
        keywords.put("class",   TokenType.CLASS);
        keywords.put("else",    TokenType.ELSE);
        keywords.put("false",   TokenType.FALSE);
        keywords.put("for",     TokenType.FOR);
        keywords.put("fun",     TokenType.FUN);
        keywords.put("if",      TokenType.IF);
        keywords.put("nil",     TokenType.NIL);
        keywords.put("print",   TokenType.PRINT);
        keywords.put("return",  TokenType.RETURN);
        keywords.put("super",   TokenType.SUPER);
        keywords.put("this",    TokenType.THIS);
        keywords.put("true",    TokenType.TRUE);
        keywords.put("var",     TokenType.VAR);
        keywords.put("while",   TokenType.WHILE);
    }
    private int start = 0;
    private int current = 0;
    private int line = 1;

    Scanner (String source) {
        this.source = source;
    }

    List<Token> scanTokens() {
        while (!isAtEnd()) {
            start = current;
            scanToken();
        }
        
        tokens.add(new Token(TokenType.EOF, "", null, line));
        return tokens;
    }

    private void scanToken() {
        char c = advance();
        switch (c) {
            case '(': addToken(TokenType.LEFT_PAREN); break;
            case ')': addToken(TokenType.RIGHT_PAREN); break;
            case '{': addToken(TokenType.LEFT_BRACE); break;
            case '}': addToken(TokenType.RIGHT_BRACE); break;
            case ',': addToken(TokenType.COMMA); break;
            case '.': addToken(TokenType.DOT); break;
            case '-': addToken(TokenType.MINUS); break;
            case '+': addToken(TokenType.PLUS); break;
            case ';': addToken(TokenType.SEMICOLON); break;
            case '*': addToken(TokenType.STAR); break;
            case '!': addToken(match('=') ? TokenType.BANG_EQUAL : TokenType.BANG); break;
            case '=': addToken(match('=') ? TokenType.EQUAL_EQUAL : TokenType.EQUAL); break;
            case '<': addToken(match('=') ? TokenType.LESS_EQUAL : TokenType.LESS); break;
            case '>': addToken(match('=') ? TokenType.GREATER_EQUAL : TokenType.GREATER); break;
            case '/':
                if (match('/')) // Comment
                    while (peek() != '\n' && !isAtEnd())
                        advance();
                else if (match('*')) // Multi-line comment
                    multiLineComment();
                else
                    addToken(TokenType.SLASH);
                break;
            case ' ':
            case '\r':
            case '\t':
                break;
            case '\n':
                line++;
                break;
            case '"': string(); break;
            default:
                if (isDigit(c))
                    number();
                else if (isAlpha(c))
                    identifier();
                else
                    Lox.error(line, "Unexpected character.");
                break;
        }
    }

    private void string() {
        while (peek() != '"' && !isAtEnd()) {
            if (peek() == '\n')
                line++;
            advance();
        }

        if (isAtEnd()) {
            Lox.error(line, "Unterminated string.");
            return;
        }

        // consume the closing "
        advance();

        String value = source.substring(start + 1, current - 1);
        addToken(TokenType.STRING, value);
    }
    private void number() {
        Double res = source.charAt(current - 1) - 48.0;
        do {
            char c = peek();
            res *= 10;
            res += c - 48;
            advance();
         } while (isDigit(peek()));

        // check for mantissa
        if (peek() == '.' && isDigit(peekNext())) {
            advance(); // consume .
            Double mantissa = -1.0;
            do {
                int c = peek() - 48;
                res += c * Math.pow(10.0, mantissa);
                mantissa--;
                advance();
            } while (isDigit(peek()));
        }
        addToken(TokenType.NUMBER, 
            res);
            // Double.parseDouble(source.substring(start, current)));
    }
    private void identifier() {
        while (isAlphaNumeric(peek())) advance();

        String text = source.substring(start, current);
        TokenType type = keywords.get(text);
        if (type == null) type = TokenType.IDENTIFIER;

        addToken(type);
    }
    private void multiLineComment() { // Re: prompt, nested comments don't really seem worth it.
        int openCount = 1;
        int closeCount = 0;

        while (openCount != closeCount) {
            while( !isAtEnd() && peek() != '*' && peek() != '/' ) {
                if (peek() == '\n')
                    line++;
                advance();
            }
            if (match('/') && peek() == '*') { // nested comment
                openCount++;
                advance();
            }
            else if (match('*') && peek() == '/') { // closing comment
                closeCount++;
                advance();
            }
            else if (isAtEnd()) {
                Lox.error(line, "Comment was not closed.");
                return;
            }
        }
    }


    private char advance() { return source.charAt(current++); }
    private void addToken(TokenType type) { addToken(type, null); }
    private void addToken(TokenType type, Object literal) {
        String text = source.substring(start, current);
        tokens.add(new Token(type, text, literal, line));
    }
    private boolean match(char expected) {
        if (isAtEnd()) return false;
        if (source.charAt(current) != expected) return false;
        current++;
        return true;
    }
    private char peek() {
        if (isAtEnd()) return '\0';
        return source.charAt(current);
    }
    private char peekNext() {
        if (current + 1 > source.length()) return '\0';
        return source.charAt(current + 1);
    }
    private boolean isDigit(char c) { return '0' <= c && c <= '9'; }
    private boolean isAlpha(char c) { return 'a' <= c && c <='z' || 'A' <= c && c <= 'Z' || c == '_'; }
    private boolean isAlphaNumeric(char c) { return isAlpha(c) || isDigit(c); }
    

    private boolean isAtEnd() { return current >= source.length(); }
}
