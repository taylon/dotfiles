" polyglot
" TODO(taylon): figure out what this is and add a comment
let g:polyglot_disabled = ['lifelines'] 

call plug#begin('~/.vim/plugged')

" Visuals related stuff
" TODO(taylon): update this to taylon/theme.vim
Plug 'joshdick/onedark.vim'

if has('nvim')
  Plug 'kyazdani42/nvim-web-devicons'

  Plug 'tami5/sqlite.lua'
  if has('win32')
    let g:sqlite_clib_path = $DOTFILES_PATH . '/windows/dlls/sqlite3/sqlite3.dll'
  endif

  Plug 'nvim-lua/plenary.nvim'
  Plug 'nvim-telescope/telescope.nvim'
  Plug 'nvim-telescope/telescope-fzy-native.nvim'
  Plug 'nvim-telescope/telescope-frecency.nvim'
  Plug 'nvim-telescope/telescope-project.nvim'
  Plug 'nvim-telescope/telescope-vimspector.nvim'
  Plug 'fannheyward/telescope-coc.nvim'

  Plug 'norcalli/nvim-colorizer.lua'

  Plug 'nvim-treesitter/nvim-treesitter', {'do': ':TSUpdate'}
  Plug 'nvim-treesitter/nvim-treesitter-textobjects'

  Plug 'windwp/nvim-autopairs'
  Plug 'ggandor/lightspeed.nvim'
  Plug 'numToStr/Comment.nvim'

  " Plug 'Olical/conjure', {'tag': 'v4.6.0'}
  " Plug 'Olical/aniseed', { 'tag': 'v3.8.0' }
  " Plug 'bakpakin/fennel.vim'
endif

" Language stuff
Plug 'sheerun/vim-polyglot'
Plug 'guns/vim-sexp'
Plug 'dummyunit/vim-fastbuild'

" Text Objects
Plug 'wellle/targets.vim'
Plug 'kanA/vim-textobj-user'
Plug 'kana/vim-textobj-entire'
Plug 'thinca/vim-textobj-comment'
Plug 'bkad/CamelCaseMotion'

" Files
Plug 'junegunn/fzf', { 'do': { -> fzf#install() } }
Plug 'junegunn/fzf.vim'
if has('unix')
  Plug 'taylon/fzf-filemru'
endif
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
  " coc-pyright
  " coc-stylelintplus
  " coc-tsserver
  " coc-rls
  " coc-clangd

" General
Plug 'tpope/vim-surround'
Plug 'tpope/vim-repeat'
Plug 'alvan/vim-closetag'
Plug 'andymass/vim-matchup'
Plug 'SirVer/ultisnips'
Plug 'mg979/vim-visual-multi'
Plug 'liuchengxu/vista.vim'
Plug 'romainl/vim-cool' 
Plug 'puremourning/vimspector'

" Under evaluation/wanting to remove soon
" Plug 'vimwiki/vimwiki'
Plug 'matze/vim-move'
Plug 'scrooloose/nerdtree'

call plug#end()

" CamelCaseMotion
let g:camelcasemotion_key = '<localleader>'
imap <silent> <c-left> <c-o><Plug>CamelCaseMotion_b
imap <silent> <c-right> <c-o><Plug>CamelCaseMotion_w

" commentary
autocmd FileType c setlocal commentstring=\/\/\ %s


" clever-f
let g:clever_f_smart_case = 1
map ; <Plug>(clever-f-repeat-forward)
map , <Plug>(clever-f-repeat-back)


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

vmap <s-down> <Plug>MoveBlockDown
nmap <s-down> <Plug>MoveLineDown
vmap <s-up> <Plug>MoveBlockUp
nmap <s-up> <Plug>MoveLineUp


" NERDTree
" Always use NERDTree by opening it in a split and replacing netwr
let g:NERDTreeHijackNetrw = 1
map <leader>e :rightbelow vsplit<Enter> :execute 'e '.fnameescape(getcwd())<Enter>


" devicons
" disabling icons because there is a bug in nerdtree, why do I still have
" nerdtree installed anyway?
let g:webdevicons_enable_nerdtree = 0


" coc
nmap <leader>rr <Plug>(coc-rename)
nnoremap <silent> <leader>t :CocCommand clangd.switchSourceHeader<Enter>

" Golang auto format
autocmd BufWritePre *.go :silent call CocAction('runCommand', 'editor.action.organizeImport')

" clangd
" autocmd BufReadPost,BufNewFile *.c,*.cpp nnoremap <silent> <leader>t :CocCommand clangd.switchSourceHeader<enter>

" Gotos
nmap <silent> gd <Plug>(coc-definition)
" nmap <silent> gr <Plug>(coc-references)
nmap <silent> gr :Telescope coc references<enter>
" nnoremap <silent> ge :CocFzfList diagnostics<enter>
nnoremap <silent> ge :Telescope coc workspace_diagnostics<enter>

" A normal mapping for this for whatever reason does not work
" when you try to go to a definition that is in another file.
" A function works though
function s:GoToDefinitionInSplit()
  :rightbelow vsplit
  execute "normal \<Plug>(coc-type-definition)"
endfunction

nnoremap <leader>gd :call <SID>GoToDefinitionInSplit()<Enter>

" Actions
nnoremap <leader>a :CocAction<Enter>

" Show documentation in preview window
function! s:show_documentation()
  if (index(['vim','help'], &filetype) >= 0)
    execute 'h '.expand('<cword>')
  elseif (coc#rpc#ready())
    call CocActionAsync('doHover')
  else
    execute '!' . &keywordprg . " " . expand('<cword>')
  endif
endfunction

nnoremap <silent> <leader>i :call <SID>show_documentation()<Enter>

" Highlight symbol under cursor on CursorHold
autocmd CursorHold * silent call CocActionAsync('highlight')


" vim-closetag
let g:closetag_filetypes = 'html,typescript.tsx,javascript.jsx'
let g:closetag_regions =  {
\ 'typescript.tsx': 'jsxRegion,tsxRegion',
\ 'javascript.jsx': 'jsxRegion',
\ }


" FZF
" nnoremap <leader>rg :Rg<space>
nnoremap <leader>rg :Telescope live_grep<enter>
nnoremap <leader>wi :Rg WHERE_I_WAS\(taylon\)<enter>

if has('win32')
  nnoremap <silent> <f12> :Telescope find_files<enter>
else
  nnoremap <silent> <f12> :lua require("telescope").extensions.frecency.frecency { sorter = require('telescope.config').values.file_sorter() }<enter>
  " nnoremap <silent> <f12> :FilesMru --tiebreak=end<Enter>
  " nnoremap <silent> <f12> :FZF
endif

let g:fzf_layout = { 'window': { 'width': 1, 'height': 0.7 } }


" fzf-project
let g:fzfSwitchProjectGitInitBehavior = 'none'
let g:fzfSwitchProjectWorkspaces = ['~/programming']

if has('win32')
  " nnoremap <silent> <c-f12> :FzfSwitchProject<enter>
  nnoremap <silent> <f36> :Telescope project<enter>
else
  " f36 maps to <c-f12> which in my keyboard is close to home row
  " to figure out this enigma look at "showkeys -a" to see what comes
  " out of the <c-f12> keypress, then use terminfo (nvim -V3log) to see
  " what keycode matches the output of showkeys
  "
  " in MacOS you do "printf '\x1b[?1h'; cat -v" or "kitty +kitten show_key" 
  " since we don't have showkeys there
  nnoremap <silent> <f36> :FzfSwitchProject<enter>
endif


" File Operations (eunuch and coc)
nnoremap <leader>fd :Delete<Enter>
nnoremap <leader>fr :CocCommand workspace.renameCurrentFile<Enter>

" commentary
autocmd FileType c,cpp setlocal commentstring=\/\/\ %s


" Git
nmap <leader>gr <Plug>(GitGutterUndoHunk)
nmap <leader>gp <Plug>(GitGutterPreviewHunk)


" splitjoin
" nnoremap sj :SplitjoinJoin<Enter>
" nnoremap ss :SplitjoinSplit<Enter>


" Vista
" let g:vista_fzf_preview = ['right:50%']
let g:vista_keep_fzf_colors = 1
let g:vista_fzf_show_line_numbers = 0
let g:vista_fzf_show_source_line = 0
noremap <silent> <leader><F12> :Telescope coc workspace_symbols<enter>
" noremap <silent> <leader><F12> :call vista#finder#fzf#Run('coc')<Enter>
" noremap <silent> <leader><F12> :Vista finder<Enter>
" let g:vista_default_executive = 'coc'


" sexp
" let g:sexp_filetypes = 'clojure,scheme,lisp,timl,fennel'


" vimspector
nmap <f9><enter> <Plug>VimspectorContinue
" nmap <f9><enter> :Telescope vimspector configurations<enter>
nmap <silent> <f9>s :call vimspector#Reset()<enter>
nmap <f9>r <Plug>VimpectorRestart
nmap <f9>b <Plug>VimspectorToggleBreakpoint
nmap <silent> <f9>c :call vimspector#ClearBreakpoints()<enter>
nmap <f9>h <Plug>VimspectorRunToCursor
nmap <f9>o <Plug>VimspectorStepOver
nmap <f9>i <Plug>VimspectorStepInto
nmap <f9>m <Plug>VimspectorBalloonEval
xmap <f9>m <Plug>VimspectorBalloonEval

let g:vimspector_sign_priority = {
  \    'vimspectorBP':         11,
  \    'vimspectorBPCond':     11,
  \    'vimspectorBPDisabled': 11,
  \ }

function! s:vimspector_customize_ui()
  call win_gotoid(g:vimspector_session_windows.output)
  quit

  " call win_gotoid(g:vimspector_session_windows.stack_trace)
  " quit

  call win_gotoid(g:vimspector_session_windows.variables)
  resize -10
endfunction

function s:vimspector_setup_terminal()
  call win_gotoid(g:vimspector_session_windows.code)
  wincmd j
  quit
  resize +10
endfunction

augroup VimspectorUICustomisation
  autocmd!
  autocmd User VimspectorUICreated call s:vimspector_customize_ui()
  autocmd User VimspectorTerminalOpened call s:vimspector_setup_terminal()
augroup END


" VimWiki
 let wiki = {}
 let wiki.nested_syntaxes = {'python': 'python', 'c++': 'cpp', 'reason': 'reason'}
 let g:vimwiki_list = [wiki]

 " let g:vimwiki_list = [{
 " \  'path': '~/vimwiki/',
 " \  'syntax': 'markdown', 
 " \  'ext': '.md',
 " \}]


" lightspeed
nmap s <Plug>Lightspeed_s


if has('nvim')
  lua require'colorizer'.setup()

  lua <<
    -- autopairs
    local nvim_autopairs = require("nvim-autopairs")
    nvim_autopairs.setup()

    _G.MUtils= {}
    MUtils.completion_confirm=function()
      if vim.fn.pumvisible() ~= 0  then
          return nvim_autopairs.esc("<cr>")
      else
        return nvim_autopairs.autopairs_cr()
      end
    end

    vim.api.nvim_set_keymap("i" , "<CR>", "v:lua.MUtils.completion_confirm()", {expr = true , noremap = true})
    -- autopairs

    -- telescope
    require("telescope").setup {
      defaults = {
        prompt_prefix = "",
        selection_caret = "⮞ ",

        -- sorting_strategy = "ascending",

        layout_strategy = "vertical",
        layout_config = {
          -- prompt_position = "top",
          height = 0.99,
          width  = 0.99,
          -- preview_width = 0.60,
        },
      },

      extensions = {
        frecency = {
          ignore_patterns = {"*.git/*", "*/tmp/*", "External/*"},
          default_workspace = "CWD",
          show_filter_column = false,
          show_unindexed = false,
        },

        project = {
          base_dirs = {
            "~/programming",
          },
        },
      },
    }

    require("telescope").load_extension("fzy_native")
    require("telescope").load_extension("project")
    require("telescope").load_extension("coc")
    require("telescope").load_extension("vimspector")
    require("telescope").load_extension("frecency")
    -- telescope

    require("lightspeed").setup {
      -- highlight_unique_chars = true,

      -- :hi LightspeedGreywash guifg=none guibg=none 
      -- grey_out_search_area = false,
    }

    require("Comment").setup()

    require("nvim-treesitter.configs").setup {
      ensure_installed = "all",

      highlight = {
        enable = true,              
      },

      textobjects = {
        select = {
          enable = true,

          -- Automatically jump forward to textobj, similar to targets.vim 
          lookahead = true,

          keymaps = {
            ["af"] = "@function.outer",
            ["if"] = "@function.inner",
          },
        },

        move = {
          enable = false,
        },
      },
    }
.
endif

