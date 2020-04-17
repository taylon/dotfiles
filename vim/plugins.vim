call plug#begin('~/.vim/plugged')

" Color related stuff
Plug 'joshdick/onedark.vim'
Plug 'luochen1990/rainbow'
Plug 'ap/vim-css-color'
Plug 'machakann/vim-highlightedyank'

" Language stuff
Plug 'sheerun/vim-polyglot'
Plug 'jparise/vim-graphql'

" Text Objects
Plug 'wellle/targets.vim'

" fzf
Plug '/usr/local/opt/fzf'
Plug 'junegunn/fzf.vim'
Plug 'taylon/fzf-filemru'

" coc
Plug 'neoclide/coc.nvim', {'branch': 'release'}
" Extensions
" coc-tsserver
" coc-prettier
" coc-json
" coc-css 
" coc-python

" Movement
Plug 'rhysd/clever-f.vim'
Plug 'easymotion/vim-easymotion'
Plug 'bkad/CamelCaseMotion'
Plug 'matze/vim-move'
Plug 'unblevable/quick-scope'

" General
Plug 'tomtom/tcomment_vim'
Plug 'tpope/vim-surround'
Plug 'tpope/vim-repeat'
Plug 'tpope/vim-eunuch'
Plug 'tpope/vim-fugitive'
Plug 'yggdroot/indentline'
Plug 'jiangmiao/auto-pairs'
Plug 'alvan/vim-closetag'
Plug 'airblade/vim-gitgutter'
Plug 'andymass/vim-matchup'
Plug 'SirVer/ultisnips'
Plug 'scrooloose/nerdtree'
Plug 'thaerkh/vim-workspace'
Plug 'terryma/vim-multiple-cursors'

Plug 'ryanoasis/vim-devicons'

call plug#end()

" CamelCaseMotion
let g:camelcasemotion_key = '<localleader>'
imap <silent> <C-Left> <C-o><Plug>CamelCaseMotion_b
imap <silent> <C-Right> <C-o><Plug>CamelCaseMotion_w

" clever-f
let g:clever_f_smart_case = 1
let g:clever_f_chars_match_any_signs = ';'

" workspace
let g:workspace_session_directory = $HOME.'/.vim/sessions/'
let g:workspace_autosave = 0
let g:workspace_autosave_untrailspaces = 0
let g:workspace_persist_undo_history = 0 " This is already setup in vimrc
let g:workspace_create_new_tabs = 0 " Do not create new tabs when calling vim with a file argument
let g:workspace_session_disable_on_args = 1 " Enable it only when calling vim without any arguments

" UltiSnips
let g:UltiSnipsSnippetsDir = $HOME.'/.vim/UltiSnips'
let g:UltiSnipsSnippetDirectories = [$HOME.'/.vim/UltiSnips'] 
let g:UltiSnipsExpandTrigger = "<tab>"
let g:UltiSnipsJumpForwardTrigger="<tab>"

" move
let g:move_map_keys = 0

vmap H <Plug>MoveBlockDown
vmap K <Plug>MoveBlockUp
vmap <S-Down> <Plug>MoveBlockDown
vmap <S-Up> <Plug>MoveBlockUp

nmap K <Plug>MoveLineUp
nmap H <Plug>MoveLineDown
nmap <S-Down> <Plug>MoveLineDown
nmap <S-Up> <Plug>MoveLineUp

" NERDTree
" Always use NERDTree by opening it in a split and replacing netwr
let g:NERDTreeHijackNetrw = 1
map <leader>e :rightbelow vsplit<Enter> :execute 'e '.fnameescape(getcwd())<Enter>

" easymotion
let g:EasyMotion_do_mapping = 0 " Disable default mappings
let g:EasyMotion_smartcase = 1
let g:EasyMotion_keys = 'seriaowyfulpdkchx.,zgmtn'

map <localleader>s <Plug>(easymotion-bd-w)
map <localleader><localleader> <Plug>(easymotion-s)
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

" Golang auto format
autocmd BufWritePre *.go :call CocAction('runCommand', 'editor.action.organizeImport')

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


" FZF
nnoremap <silent> <F12> :FilesMru --tiebreak=end<Enter>
inoremap <silent> <F12> <ESC>:FilesMru --tiebreak=end<Enter>

nnoremap <D-p> :Command<Enter>
inoremap <D-p> <ESC>:Command<Enter>

