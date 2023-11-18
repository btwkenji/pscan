## Port scanner using c++

###

<div align="center">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" height="150" alt="cplusplus logo"  />
</div>

###

## Project structure:

```rust
├── LICENSE
├── portscan.cpp
└── README.md
```

## Installation

```shell
git clone https://github.com/kenjitheman/portscanner
```

## Usage

- Compile c++

```shell
g++ portscanner.cpp -o portscanner
```

- Run the portscanner:

```shell
./portscanner <targetIP> <timeout>
```

- Example:

```shell
./portscanner 192.168.1.100 2
```

- Scan all ports on the IP address 192.168.1.100 with a timeout of 2 seconds for each port.

## Contributing

- Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

## License

- [MIT](https://choosealicense.com/licenses/mit/)
