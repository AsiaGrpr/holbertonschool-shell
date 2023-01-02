gitpush(){
          git add "$1"
          git commit -m"$2"
          git push
          }
alias gp=gitpush
