let g:onedark_hide_endofbuffer = 1
augroup colorset
  autocmd!
  let s:blue = { "gui": "#61AFEF", "cterm": "39", "cterm16": "4" }
  autocmd ColorScheme * call onedark#set_highlight("MatchParen", { "fg": s:blue })
augroup END

colorscheme onedark

" Set highlightedyank color to match the onedark theme visual selection
highlight HighlightedyankRegion guibg=#3E4452 guifg=NONE

" Blink cursor every time files are saved
function! s:blink_cursor()
  highlight Cursor guibg=#a6d7ff
  sleep 150m
  highlight Cursor guibg=#61afef
endfunction

autocmd BufWritePost * :call <SID>blink_cursor()

