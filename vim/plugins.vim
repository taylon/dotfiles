call plug#begin('~/.vim/plugged')

" Visuals related stuff
Plug 'joshdick/onedark.vim'
Plug 'luochen1990/rainbow'
Plug 'ryanoasis/vim-devicons'

if has('nvim')
  Plug 'norcalli/nvim-colorizer.lua'
  Plug 'nvim-treesitter/nvim-treesitter'
endif

" Language stuff
Plug 'sheerun/vim-polyglot'
Plug 'jparise/vim-graphql'

" Text Objects
Plug 'wellle/targets.vim'
Plug 'kanA/vim-textobj-user'
Plug 'kana/vim-textobj-entire'
Plug 'thinca/vim-textobj-comment'
Plug 'bkad/CamelCaseMotion'

" Files
Plug '/usr/local/opt/fzf'
Plug 'junegunn/fzf.vim'
Plug 'taylon/fzf-filemru'
Plug 'benwainwright/fzf-project'
Plug 'thaerkh/vim-workspace'
Plug 'tpope/vim-fugitive'
Plug 'airblade/vim-gitgutter'
Plug 'tpope/vim-eunuch'
Plug 'duggiefresh/vim-easydir'

" coc
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'antoinemadec/coc-fzf', {'branch': 'release'}
" Extensions:
  " coc-css
  " coc-diagnostic
  " coc-eslint
  " coc-json
  " coc-prettier
  " coc-python
  " coc-stylelintplus
  " coc-tsserver
  " coc-rls
  " coc-actions

" Movement
Plug 'rhysd/clever-f.vim'
Plug 'easymotion/vim-easymotion'
Plug 'unblevable/quick-scope'

" General
" Plug 'tomtom/tcomment_vim'
Plug 'tpope/vim-surround'
Plug 'tpope/vim-repeat'
Plug 'tpope/vim-commentary'
Plug 'yggdroot/indentline'
" Plug 'jiangmiao/auto-pairs'
Plug 'alvan/vim-closetag'
Plug 'andymass/vim-matchup'
Plug 'SirVer/ultisnips'
Plug 'terryma/vim-multiple-cursors'
Plug 'vhdirk/vim-cmake'
Plug 'liuchengxu/vista.vim'
Plug 'romainl/vim-cool' 

" Under evaluation/wanting to remove soon
Plug 'vimwiki/vimwiki'
Plug 'matze/vim-move'
Plug 'scrooloose/nerdtree'
Plug 'AndrewRadev/splitjoin.vim'
Plug 'cohama/lexima.vim'



call plug#end()

" CamelCaseMotion
let g:camelcasemotion_key = '<localleader>'
imap <silent> <C-Left> <C-o><Plug>CamelCaseMotion_b
imap <silent> <C-Right> <C-o><Plug>CamelCaseMotion_w


" clever-f
let g:clever_f_smart_case = 1


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

vmap <S-Down> <Plug>MoveBlockDown
vmap <S-Up> <Plug>MoveBlockUp

nmap <S-Down> <Plug>MoveLineDown
nmap <S-Up> <Plug>MoveLineUp


" NERDTree
" Always use NERDTree by opening it in a split and replacing netwr
let g:NERDTreeHijackNetrw = 1
map <leader>e :rightbelow vsplit<Enter> :execute 'e '.fnameescape(getcwd())<Enter>


" devicons
" disabling icons because there is a bug in nerdtree 
let g:webdevicons_enable_nerdtree = 0


" easymotion
let g:EasyMotion_do_mapping = 0 " Disable default mappings
let g:EasyMotion_smartcase = 1
let g:EasyMotion_keys = 'tnseriaowyfulpdhc,x.z/gmvkbjq;'

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
" set nobackup
" set nowritebackup

nmap <leader>rr <Plug>(coc-rename)

" Golang auto format
autocmd BufWritePre *.go :call CocAction('runCommand', 'editor.action.organizeImport')

" Gotos
nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gr <Plug>(coc-references)

" A normal mapping for this for whatever reason does not work
" when you try to go to a definition that is in another file.
" A function works though
function s:GoToDefinitionInSplit()
  :rightbelow vsplit
  execute "normal \<Plug>(coc-type-definition)"
endfunction

nnoremap <leader>gd :call <SID>GoToDefinitionInSplit()<Enter>

" coc-actions
" nnoremap <leader>a :CocAction<Enter>
" Remap for do codeAction of selected region
nmap <silent> <leader>a :<C-u>execute 'CocCommand actions.open ' . visualmode()<CR>

" Show documentation in preview window
function! s:show_documentation()
  if (index(['vim','help'], &filetype) >= 0)
    execute 'h '.expand('<cword>')
  else
    call CocAction('doHover')
  endif
endfunction

nnoremap <silent> <leader>d :call <SID>show_documentation()<Enter>

" Highlight symbol under cursor on CursorHold
autocmd CursorHold * silent call CocActionAsync('highlight')


" vim-closetag
let g:closetag_filetypes = 'html,typescript.tsx,javascript.jsx'
let g:closetag_regions =  {
\ 'typescript.tsx': 'jsxRegion,tsxRegion',
\ 'javascript.jsx': 'jsxRegion',
\ }


" FZF
nnoremap <silent> <f12> :FilesMru --tiebreak=end<Enter>
inoremap <silent> <f12> <esc>:FilesMru --tiebreak=end<enter>

nnoremap <leader>rg :Rg<space>
nnoremap <silent> <leader>; :Commands<enter> 

nnoremap <c-p> :Command<enter>
inoremap <c-p> <esc>:Command<enter>

let g:fzf_layout = { 'window': { 'width': 1, 'height': 0.7 } }

" fzf-project
let g:fzfSwitchProjectGitInitBehavior = 'none'
let g:fzfSwitchProjectWorkspaces = ['~/Development']
" f36 maps to <c-f12> which in my keyboard is close to home row
" to figure out this enigma look at "showkeys -a" to see what comes
" out of the <c-f12> keypress, then use terminfo (nvim -V3log) to see
" what keycode matches the output of showkeys
nnoremap <f36> :FzfSwitchProject<enter>


" File Operations (eunuch and coc)
nnoremap <leader>fd :Delete<Enter>
nnoremap <leader>fr :CocCommand workspace.renameCurrentFile<Enter>


" Git
nmap <leader>gr <Plug>(GitGutterUndoHunk)


" splitjoin
nnoremap sj :SplitjoinJoin<Enter>
nnoremap ss :SplitjoinSplit<Enter>


" Vista
let g:vista_fzf_preview = ['right:50%']
let g:vista_keep_fzf_colors = 1
let g:vista_fzf_show_line_numbers = 0
let g:vista_fzf_show_source_line = 0
noremap <silent> <leader><F12> :Vista finder<Enter>
" let g:vista_default_executive = 'coc'


" VimWiki
 let wiki = {}
 let wiki.nested_syntaxes = {'python': 'python', 'c++': 'cpp', 'reason': 'reason'}
 let g:vimwiki_list = [wiki]

 " let g:vimwiki_list = [{
 " \  'path': '~/vimwiki/',
 " \  'syntax': 'markdown', 
 " \  'ext': '.md',
 " \}]

if has('nvim')
  lua require'colorizer'.setup()

  lua <<
    require'nvim-treesitter.configs'.setup {
      ensure_installed = "all",

      highlight = {
        enable = true,              
      },

      textobjects = {
        select = {
          enable = true,

          keymaps = {
            ["af"] = "@function.outer",
            ["if"] = "@function.inner",
          },
        },

        move = {
          enable = true,

          goto_next_start = {
            ["<M-Down>"] = "@function.outer",
          },

          -- goto_next_end = {
          --  ["<M-Down>"] = "@function.outer",
          -- },

          goto_previous_start = {
           ["<M-Up>"] = "@function.outer",
          },

          -- goto_previous_end = {
          --  ["<M-Up>"] = "@function.outer",
          -- },
        },
      },
    }
.
endif

