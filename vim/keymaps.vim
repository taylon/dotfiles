let mapleader="\<C-\>" " Setup on the keyboard as one key
let maplocalleader="\<space>"

" Remap j and h to work better with Colemak-DHm
set nolangremap
set langmap=hj,HJ,jh,JH

" Ctrl-tab to move to last position
nnoremap <C-s-Tab> <C-o>

" Save with Ctrl-s
nnoremap <D-s> :w<Enter>
inoremap <D-s> <Esc>:w<Enter>

" New line in Normal Mode
nnoremap <Enter> o<Esc>
nnoremap <S-Enter> O<Esc>

" New line in Insert mode
inoremap <D-Enter> <Esc>o
inoremap <D-S-Enter> <Esc><S-o>

" Clear search highlight with Esc
nnoremap <silent> <Esc> :noh<Enter><Esc>
nnoremap <Esc>^[ <Esc>^[

" Splits
nnoremap <leader>v :rightbelow vsplit<Enter>
nnoremap <leader>s :rightbelow split<Enter>

nnoremap <leader><Right> <C-w><Right>
nnoremap <leader>l <C-w><Right>

nnoremap <leader><Left> <C-w><Left>
nnoremap <leader>j <C-w><Left>

nnoremap <leader><Up> <C-w><Up>
nnoremap <leader>k <C-w><Up>

nnoremap <leader><Down> <C-w><Down>
nnoremap <leader>h <C-w><Down>

" Folding
nnoremap <D-[> za

