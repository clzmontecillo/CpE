#!/usr/bin/python3

# This script uses MD5 Hashing to verify if the first line of text inside a text file is a palindrome or not

import re
import hashlib

inputFile = input(str("Input File Location: "))

def main(): 
    file = open(inputFile,'r')
    readData(file)

def readData(fileInput):
    phraseRaw = fileInput.read()
    phraseStripped = phraseRaw.strip()
    phraseLowered = phraseStripped.lower()
    phraseStrip1 = phraseLowered.replace(","," ")
    phraseStrip2 = phraseStrip1.replace("#"," ") 
    phraseStrip3 = phraseStrip2.replace("."," ")
    finalPhrase = phraseStrip3.split()
    countWords(finalPhrase)

def countWords(phraseInput):
    joinedPhrase = ''.join(map(str,phraseInput))    # joined string (whitespace-free)
    keyNo = len(joinedPhrase)   # no of characters
    i = 0
    original = joinedPhrase
    reverse = ''.join(reversed(original))
    isPalindrome(original,reverse)

def isPalindrome(original,reverse):
    hashOriginal = hashlib.md5(original.encode('utf-8')).hexdigest()
    hashReverse = hashlib.md5(reverse.encode('utf-8')).hexdigest()
    if(hashReverse == hashOriginal):
      print("Palindrome.")
    else:
      print("Not a Palindrome.")

main()
