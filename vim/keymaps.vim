let mapleader="\<F6>"
let maplocalleader="\<space>"

" Remap j and h to work better with Colemak-DHm
set nolangremap
set langmap=hj,HJ,jh,JH

" Y should behave just like D or C
map Y y$

" Positional movement
nnoremap <F7> <C-o>
nnoremap <F10> <C-i>

" Make scolling keybindings more consistent
nnoremap <C-k> <C-u>
nnoremap <C-h> <C-d>

" Prevent A-direction jumps to be stored in the jumplist
nnoremap <silent> <M-Up> :<C-u>execute "keepjumps norm! " . v:count1 . "{"<Enter>
nnoremap <silent> <M-k> :<C-u>execute "keepjumps norm! " . v:count1 . "{"<Enter>
nnoremap <silent> <M-Down> :<C-u>execute "keepjumps norm! " . v:count1 . "}"<Enter>
nnoremap <silent> <M-h> :<C-u>execute "keepjumps norm! " . v:count1 . "}"<Enter>

" C and D will be in the same position in the keyboard,
" setup by the keyboard firmware
if has("macunix")
  " Save with Ctrl-s
  nnoremap <silent> <D-s> :silent w<Enter>
  inoremap <silent> <D-s> <Esc>:silent w<Enter>

  " New line in Insert mode
  inoremap <D-Enter> <Esc>o
  inoremap <D-S-Enter> <Esc><S-o>
else
  nnoremap <silent> <C-s> :silent w<Enter>
  inoremap <silent> <C-s> <Esc>:silent w<Enter>

  inoremap <C-Enter> <Esc>o
  inoremap <C-S-Enter> <Esc><S-o>
endif

" New line in Normal Mode
nnoremap <Enter> o<Esc>
nnoremap <S-Enter> O<Esc>

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

