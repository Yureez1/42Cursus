#!/bin/bash
# Run this script from the root of your 42Cursus repo to clean generated files
# Usage: bash cleanup.sh

echo "Cleaning generated files from git tracking..."

# Remove .DS_Store files
find . -name ".DS_Store" -not -path './.git/*' -exec git rm --cached {} \; 2>/dev/null
find . -name ".DS_Store" -not -path './.git/*' -delete 2>/dev/null

# Remove .o files
find . -name "*.o" -not -path './.git/*' -exec git rm --cached {} \; 2>/dev/null
find . -name "*.o" -not -path './.git/*' -delete 2>/dev/null

# Remove .a files
find . -name "*.a" -not -path './.git/*' -exec git rm --cached {} \; 2>/dev/null
find . -name "*.a" -not -path './.git/*' -delete 2>/dev/null

# Remove .vscode
find . -name ".vscode" -type d -exec git rm -r --cached {} \; 2>/dev/null
find . -name ".vscode" -type d -exec rm -rf {} \; 2>/dev/null

# Remove objs/ and obj/ directories
find . -name "objs" -type d -exec git rm -r --cached {} \; 2>/dev/null
find . -name "objs" -type d -exec rm -rf {} \; 2>/dev/null
find . -name "obj" -type d -exec git rm -r --cached {} \; 2>/dev/null
find . -name "obj" -type d -exec rm -rf {} \; 2>/dev/null

# Remove known binaries
BINARIES=(
    "2_Milestone/C.so_long/so_long"
    "4_Milestone/CPP_0-5/CPP01/ex00/Braiiiiiiinnnzzz"
    "4_Milestone/CPP_0-5/CPP04/ex00/Polymorph"
    "5_Milestone/CPP_6-9/CPP06/ex00/ScalarConverter"
    "5_Milestone/CPP_6-9/CPP07/ex02/Array"
    "5_Milestone/CPP_6-9/CPP08/ex02/Span"
)

for bin in "${BINARIES[@]}"; do
    if [ -f "$bin" ]; then
        git rm --cached "$bin" 2>/dev/null
        rm -f "$bin"
    fi
done

echo "Done! Now run:"
echo "  git add .gitignore"
echo "  git commit -m 'Clean repo: add .gitignore, remove generated files'"
echo "  git push"
