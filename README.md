# MarkupCLI++
A C++ project that allows for easy creation of *Markdown files* using a CLI, for **Linux**, **Windows**, and **macOS**.

## Install 

**Linux and macOS**
```
curl -sSL https://raw.githubusercontent.com/Nahida4479/MarkupCLI/main/install.sh | bash
```

**Windows**
1. Go to the [Releases](https://github.com/Nahida4479/MarkupCLI/releases/latest) page
2. Download `MarkupCLI++-windows.exe`   

## How to use?

**Linux and macOS**
```bash
MarkupCLI++ file_name.md --text 123
```

**Windows**

1. Open in Terminal
```bash
.\MarkupCLI++ file_name.md --text 123
```

> [!WARNING]
> On Windows, use `.\MarkupCLI++`.


### A command containing all the flags

```bash
MarkupCLI++ file.md --header Hello --header2 hello2 --header3 hello3 --header4 hello4 --header5 hello5 --text hi --header6 hello6 --text Hello world --note Hi --important Important information --tip install MarkupCLI++  --image photo https://cdn.hackclub.com/01a06e42-3b6f-7248-b3f9-b82a2612d31e/nevai-logo-512.png --link NevAI https://cdn.hackclub.com/01a06e42-3b6f-7248-b3f9-b82a2612d31e/nevai-logo-512.png --warning Warning --caution Caution --table yes --overwrite-file
```

> [!NOTE]
> [The result of this command.](./example_file.md)

## Flags
```bash
--header (from header2 to header6)
--text
--note
--important
--tip
--image
--link
--warning
--caution
--table
--overwrite-file
```

## How to build?
```bash
git clone https://github.com/Nahida4479/MarkupCLI.git
cd MarkupCLI
make
```
> [!NOTE] 
> `make` builds a Linux and macOS binary only. For Windows, download a pre-built binary from [Releases](https://github.com/Nahida4479/MarkupCLI/releases).

