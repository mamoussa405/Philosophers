#!/bin/bash
git add *
echo "Enter your message for commit:"
read message
git commit -m "$message"
git push