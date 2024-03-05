# My Regex Engine

This project is a regular expression engine supporting basic operations such as union, concatenation, and Kleene star. It utilizes Deterministic Finite Automata (DFA) for efficient pattern matching.

The project is yet to be fully implemented. Current state of implementation: Lexer implemented.

## Implementation

The engine is implemented using the DFA approach, which ensures efficient pattern matching with a deterministic state machine.

## Requirements

- CMake
- Any C++ compiler

## Usage

To use this regex engine, follow these steps:

1. Clone the repository
```bash
git clone https://github.com/Baxi-codes/my-regex-engine.git
cd my-regex-engine
```

2. Create a build directory:
```bash
mkdir build
cd build
```

3. Generate build files using CMake and compile:
```bash
cmake ..
make
```

## Contribution
Contributions are welcome! If you find any bugs or want to add new features, feel free to open an issue or submit a pull request.

## License
This project is licensed under version 3 of the GNU General Public License - see the LICENSE file for details.
