" This will meed the cursor always on the center of the screen
if has('autocmd')
  augroup CentralizedCursor
    autocmd!

    autocmd BufEnter,WinEnter,WinNew,VimResized *,*.*
      \ let &scrolloff=winheight(win_getid())/2

  augroup END
endif
