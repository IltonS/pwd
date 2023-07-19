# pwd
Simple password tools

### Usage:

```bash
$ pwd [-v | --version] [-h | --help]

$ pwd <command> [<args>]
```
       
### Options:
**-h, --help**    Show a help message and exit.<br>
**-v, --version** Show the program version and exit.

### Commands:

**Generate**

```bash
$ pwd generate -l <length> [ [-u] [-d] [-s] | -[u][d][s] ]
            
$ pwd generate --fort-knox
```
			 
**-l, --length**  Use this option to specify the length of the password.<br>
**-u, --upper**   Include uppercase letters in the password.<br>
**-d, --digits**  Include digits in the password.<br>
**-s, --special** Include special characters in the password.

**length** Specify the length of the password, between 4 and 16.
   
**--fort-knox** Shortcut for ```-l 16 -uds```