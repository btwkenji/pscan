<h2 align="center">port scanner using c++</h2>

###

<div align="center">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" height="150" alt="cplusplus logo"  />
</div>

###

## project structure:

```rust
├── LICENSE
├── portscan.cpp
└── README.md
```

## installation

```shell
git clone https://github.com/kenjitheman/portscanner
```

## usage

- compile c++

```shell
g++ portscanner.cpp -o portscanner
```

- run the portscanner

```shell
./portscanner <targetIP> <timeout>
```

- example:

```shell
./portscanner 192.168.1.100 2
```

- scan all ports on the IP address 192.168.1.100 with a timeout of 2 seconds for each port

## contributing

- pull requests are welcome, for major changes, please open an issue first to
  discuss what you would like to change

## license

- [MIT](https://choosealicense.com/licenses/mit/)
