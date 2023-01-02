syntax on
set number
set autoindent
set cpoptions+=n
colorscheme industry
filetype indent on
filetype plugin indent on
set tabstop=8 
set softtabstop=8
set pastetoggle=<F2>

call plug#begin()
Plug 'dense-analysis/ale'
Plug 'JuanDAC/betty-ale-vim'
call plug#end()
let g:ale_linters = {'c': ['betty-style', 'betty-doc']}
