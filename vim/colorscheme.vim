let g:onedark_hide_endofbuffer = 1
augroup colorset
  autocmd!

  let s:blue = { "gui": "#61AFEF", "cterm": "39", "cterm16": "4" }
  autocmd ColorScheme * call onedark#set_highlight("MatchParen", { "fg": s:blue })
augroup END

colorscheme onedark

highlight TextYankHighlight guibg=#3E4452 guifg=NONE

" Blink cursor every time files are saved
function! s:blink_cursor()
  highlight Cursor guibg=#a6d7ff
  sleep 150m
  highlight Cursor guibg=#61afef
endfunction

autocmd BufWritePost * :call <SID>blink_cursor()

highlight CleverFMark guibg=#e06c75 guifg=#000000 gui=bold

highlight CocHighlightText guibg=#3E4452 guifg=NONE
