let mapleader="\<F6>"
let maplocalleader="\<space>"

" Remap j and h to work better with Colemak-DHm
" set nolangremap
" set langmap=hj,HJ,jh,JH

" Y should behave just like D or C
map Y y$

" Movement
nnoremap <f7> <c-o>
nnoremap <f10> <c-i>

" Make scolling keybindings more consistent
nnoremap <c-k> <c-u>
nnoremap <c-h> <c-d>

" Prevent Alt-direction jumps to be stored in the jumplist
nnoremap <silent> <m-Up> :<c-u>execute "keepjumps norm! " . v:count1 . "{"<Enter>
nnoremap <silent> <m-k> :<c-u>execute "keepjumps norm! " . v:count1 . "{"<Enter>
nnoremap <silent> <m-Down> :<c-u>execute "keepjumps norm! " . v:count1 . "}"<Enter>
nnoremap <silent> <m-h> :<c-u>execute "keepjumps norm! " . v:count1 . "}"<Enter>

nnoremap <silent> <c-s> :silent w<enter>
inoremap <silent> <c-s> <esc>:silent w<enter>

inoremap <c-enter> <esc>o
inoremap <c-s-enter> <esc><s-o>

" New line in Normal Mode
nnoremap <Enter> o<Esc>
nnoremap <S-Enter> O<Esc>

" Splits
noremap <silent> <c-w> :q<Enter>
nnoremap <leader>v :rightbelow vsplit<Enter>
nnoremap <leader>s :rightbelow split<Enter>

nnoremap <leader><right> <c-w><right>
nnoremap <leader>l <c-w><right>

nnoremap <leader><left> <c-w><left>
nnoremap <leader>j <c-w><left>

nnoremap <leader><up> <c-w><up>
nnoremap <leader>k <c-w><up>

nnoremap <leader><down> <c-w><down>
nnoremap <leader>h <c-w><down>

" Pasting
nnoremap <leader>p v$<left>p
cnoremap <c-v> <c-r>"

