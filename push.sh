#!/bin/bash
git add *
echo -e "Enter your message for commit:\t"
read message
git commit -m "$message"
git push