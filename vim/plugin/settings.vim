set nocompatible
set backspace=indent,eol,start " allow unrestricted backspacing in insert mode

if has('wildmenu')
  set wildmenu " improved command line completion
endif

set autoindent " carry over indenting from previous line
set smarttab
set expandtab
set tabstop=2 " make tabs as wide as two spaces
set shiftwidth=2
set noshiftround " don't always indent by multiple of shiftwidth
if v:progname !=# 'vi'
  set softtabstop=-1 " use 'shiftwidth' for tab/bs at end of line
endif

" Folding
set foldmethod=syntax
set nofoldenable

set autoread " auto read files if it changes outside vim
set ignorecase
set smartcase

set hlsearch " highlight the last used search pattern.
set incsearch " highlight matched patterns as you type

" set cursor colors per mode
let &t_SI = "\<Esc>[6 q"
let &t_SR = "\<Esc>[4 q"
let &t_EI = "\<Esc>[2 q"
set cursorline " highlight current line
set noruler " don't show cursor position
set noshowmode


set pumheight=7 " limit the number of suggestions shown in the autocomplete menu

set updatecount=80 " update swapfiles every 80 chars
set updatetime=300 " cursorHold interval

set shortmess+=F " remove message when opening files
set shortmess+=W " don't echo "[w]"/"[written]" when writing
if has('patch-7.4.314')
  set shortmess+=c " completion messages
endif

set laststatus=1 " show filename in the bottom only if there is a split
if has('showcmd')
  set noshowcmd " hide command echoing
endif

set hidden " allows you to hide buffers with unsaved changes without being prompted

set signcolumn=yes " always show the signcolumn in the gutter
set number
if exists('+relativenumber')
  set relativenumber " show relative numbers in gutter
endif

" don't create root-owned files
if exists('$SUDO_USER')
  set nobackup                        
  set nowritebackup
  set noswapfile
else
  set backupdir=~/.vim/.backups
  set directory=~/.vim/.swaps
endif

if has('persistent_undo')
  if exists('$SUDO_USER')
    set noundofile
  else
    set undofile
    set undodir=~/.vim/.undo
  endif
endif

set history=1000

if exists('&belloff')
  set belloff=all
endif

set sidescrolloff=5 " same as scrolloff, but for columns
if exists('+colorcolumn')
  " highlight up to 255 columns (this is the current Vim max) beyond 'textwidth'
  let &l:colorcolumn='+' . join(range(0, 254), ',+')
endif

set formatoptions+=n " smart auto-indenting inside numbered lists
if v:version > 703 || v:version == 703 && has('patch541')
  set formatoptions+=j " remove comment leader when joining comment lines
endif

if exists('&inccommand')
  set inccommand=split " live preview of :s results              
endif

set nowrap " don't wrap lines
if has('linebreak')
  set linebreak " wrap long lines at characters in 'breakat'
endif

if has('windows')
  set splitbelow " open horizontal splits below current window
endif

if has('vertsplit')
  set splitright " open vertical splits to the right of the current window
endif

if has('syntax')
  set synmaxcol=200 " don't bother syntax highlighting long lines
endif

if has('virtualedit')
  set virtualedit=block " allow cursor to move where there is no text in visual block mode
endif

" use the OS clipboard by default
if has('unix') && !has('macunix')
  set clipboard=unnamedplus
else
  set clipboard=unnamed
endif

