if has('autocmd')
  augroup MyAutocmds
    autocmd!

    if exists('##TextYankPost')
      autocmd TextYankPost * silent! lua require'vim.highlight'.on_yank({higroup='TextYankHighlight', timeout=200})
    endif
  augroup END
endif
