call plug#begin('~/.vim/plugged')

" Color related stuff
Plug 'joshdick/onedark.vim'
Plug 'luochen1990/rainbow'
Plug 'ap/vim-css-color'

" Language stuff
Plug 'sheerun/vim-polyglot'
Plug 'jparise/vim-graphql'

" Text Objects
Plug 'wellle/targets.vim'

" fzf
Plug '/usr/local/opt/fzf'
Plug 'junegunn/fzf.vim'

" coc
Plug 'neoclide/coc.nvim', {'branch': 'release'}
" Extensions
" coc-tsserver
" coc-prettier
" coc-yank
" coc-json
" coc-css 

" General
Plug 'tomtom/tcomment_vim'
Plug 'tpope/vim-surround'
Plug 'tpope/vim-repeat'
Plug 'tpope/vim-eunuch'
Plug 'yggdroot/indentline'
Plug 'jiangmiao/auto-pairs'
Plug 'alvan/vim-closetag'
Plug 'airblade/vim-gitgutter'
Plug 'easymotion/vim-easymotion'
Plug 'adelarsq/vim-matchit'
Plug 'SirVer/ultisnips'
Plug 'scrooloose/nerdtree'

call plug#end()

" UltiSnips
let g:UltiSnipsSnippetsDir = $HOME.'/.vim/UltiSnips'
let g:UltiSnipsSnippetDirectories = [$HOME.'/.vim/UltiSnips'] 
let g:UltiSnipsExpandTrigger = "<tab>"
let g:UltiSnipsJumpForwardTrigger="<tab>"

" NERDTree
" Always use NERDTree by opening it in a split and replacing netwr
let g:NERDTreeHijackNetrw = 1
map <leader>e :rightbelow vsplit<Enter> :execute 'e '.fnameescape(getcwd())<Enter>

" easymotion
let g:EasyMotion_do_mapping = 0 " Disable default mappings
let g:EasyMotion_smartcase = 1
let g:EasyMotion_keys = 'seriaowyfulpdkchx.,zgmtn'

map <localleader>w <Plug>(easymotion-bd-w)
map <localleader>s <Plug>(easymotion-s)
nmap <localleader><localleader>s <Plug>(easymotion-overwin-f)
nmap <localleader><localleader>w <Plug>(easymotion-overwin-w)
map / <Plug>(easymotion-sn)


" Rainbow brackets
let g:rainbow_active = 1
let g:rainbow_conf = {
\	'guifgs': ['gold', 'orchid', 'lightskyblue'],
\	'ctermfgs': ['lightblue', 'lightyellow', 'lightcyan', 'lightmagenta'],
\	'guis': [''],
\	'cterms': [''],
\	'operators': '_,_',
\	'parentheses': ['start=/(/ end=/)/ fold', 'start=/\[/ end=/\]/ fold', 'start=/{/ end=/}/ fold']
\}


" coc
" Recommended settings to avoid issues
set hidden
set nobackup
set nowritebackup
set updatetime=300
set shortmess+=c

nmap <D-r> <Plug>(coc-rename)

" Gotos
nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gr <Plug>(coc-references)
nmap <silent> gt <Plug>(coc-type-definition)

" Actions
nnoremap <leader>a :CocAction<Enter>

" A normal mapping for this for whatever reason does not work
" when you try to go to a definition that is in another file.
" A function works though
function s:GoToDefinitionInSplit()
  :rightbelow vsplit
  execute "normal \<Plug>(coc-type-definition)"
endfunction

nnoremap <leader>gd :call <SID>GoToDefinitionInSplit()<Enter>

" Show documentation in preview window
function! s:show_documentation()
  if (index(['vim','help'], &filetype) >= 0)
    execute 'h '.expand('<cword>')
  else
    call CocAction('doHover')
  endif
endfunction

map <silent> <leader>d :call <SID>show_documentation()<Enter>

" Highlight symbol under cursor on CursorHold
autocmd CursorHold * silent call CocActionAsync('highlight')


" vim-closetag
let g:closetag_filetypes = 'html,typescript.tsx,javascript.jsx'
let g:closetag_regions =  {
\ 'typescript.tsx': 'jsxRegion,tsxRegion',
\ 'javascript.jsx': 'jsxRegion',
\ }


" NERDCommenter
map <D-/> <leader>c<Space>


" FZF
nnoremap <C-s-Tab> :History<Enter>
inoremap <C-s-Tab> <ESC>:History<Enter>

nnoremap <C-Tab> :Files<Enter>
inoremap <C-Tab> <ESC>:Files<Enter>

nnoremap <D-p> :Command<Enter>
inoremap <D-p> <ESC>:Command<Enter>

