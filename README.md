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

| Flag | Arguments | Markdown Output | Example |
|---|---|---|---|
| `--header` | text | `# text` | `--header Title` |
| `--text` | text | plain text | `--text Some text` |
| `--note` | text | `> [!NOTE]` | `--note Remember this` |
| `--important` | text | `> [!IMPORTANT]` | `--important Read carefully` |
| `--tip` | text | `> [!TIP]` | `--tip Try this shortcut` |
| `--warning` | text | `> [!WARNING]` | `--warning Be careful` |
| `--caution` | text | `> [!CAUTION]` | `--caution This may break things` |
| `--image` | description, link | `![description](link)` | `--image Logo https://...` |
| `--link` | description, link | `[description](link)` | `--link NevAI https://...` |
| `--table` | `yes` (confirmation) | interactive table builder | `--table yes` |
| `--overwrite-file` | *(none)* | clears the file before writing | `--overwrite-file` |"

The header also has other forms: **header2**, **header3**, **header4**, **header5**, **header6**

## How to build?
```bash
git clone https://github.com/Nahida4479/MarkupCLI.git
cd MarkupCLI
make
```
> [!NOTE] 
> `make` builds a Linux and macOS binary only. For Windows, download a pre-built binary from [Releases](https://github.com/Nahida4479/MarkupCLI/releases).

