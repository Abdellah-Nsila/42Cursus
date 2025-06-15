# 🐚 Minishell

This folder is a pointer to our **team-built Minishell project**, developed as part of the **42 Cursus**. The full codebase is hosted in a dedicated GitHub organization for collaboration:

🔗 **Organization Repository**: [Minishell13](https://github.com/Minishell13)

## 🎯 Project Objective

Minishell is a minimal Unix shell that replicates core behavior of `/bin/bash`. It supports command parsing, redirections, pipelines, environment variable expansion, subshells, and built-ins — all written from scratch in C.

This project is part of the Level 3 milestone in the 42 School curriculum and must be developed in pairs.

---

## 🏗 Project Structure

The project is divided into two repositories under the [Minishell13](https://github.com/Minishell13) organization (Those repos is just for learning and understanding concpets of the project, the implementation is not correct 100%):

### 🔹 [Minishell Parsing](https://github.com/Minishell13/Minishell_parsing)
> **Owner:** [Hamza Wahmane](https://github.com/Wahmane-Hamza)

Handles:
- Lexer/tokenizer
- Parser & AST generation
- Grouping, quotes, `&&`, `||`, and subshells
- Grammar validation

### 🔸 [Minishell Execution](https://github.com/Minishell13/Minishell_execution)
> **Owner:** [Abdellah Nsila](https://github.com/Abdellah-Nsila)

Handles:
- Environment and variable expansion
- Wildcards
- Process creation (`fork`, `execve`)
- Builtins, redirections, pipes
- Subshell evaluation
- FD isolation & restoration

---

## 📌 Key Features

- [x] AST-based execution engine
- [x] Full parsing of shell grammar
- [x] Builtin commands: `cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit`
- [x] Redirections: `<`, `>`, `>>`, `<<`
- [x] Pipes and command chaining with `|`
- [x] Logical operators `&&`, `||`
- [x] Subshells: `( ... )`
- [x] Signal handling (`Ctrl+C`, `Ctrl+\`)
- [x] Environment variable expansion (`$VAR`, `$?`)
- [x] Wildcard expansion `*` (optional)

---

## 🚀 Run Instructions

To run the shell:
1. Clone both repositories.
2. Follow the `README.md` in each repo to build the parser and executor.
3. Use a script or combined Makefile to integrate both sides.

---

## 👥 Contributors

- [Hamza Wahmane](https://github.com/Wahmane-Hamza) – Parsing logic
- [Abdellah Nsila](https://github.com/Abdellah-Nsila) – Execution logic

---

## 📚 Educational Purpose

This project is built under 42's strict constraints:
- No external libraries
- Limited libc functions
- Deep manual memory management
- Modular architecture (lexer → parser → AST → executor)

> It’s a deep dive into how shells work internally — process control, memory, file descriptors, and command parsing.

---

## 🔗 Useful Links

- 🧠 [Minishell13 GitHub Organization](https://github.com/Minishell13)
- 🔧 [Minishell Parsing Repo](https://github.com/Minishell13/Minishell_parsing)
- ⚙️ [Minishell Execution Repo](https://github.com/Minishell13/Minishell_execution)

---

> This folder acts as a documentation link and reference for the official team implementation.

