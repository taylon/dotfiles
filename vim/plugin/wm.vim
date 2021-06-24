function s:vsplit_and_grow_window()
  :silent execute '!i3-msg resize grow width 10 px or 10 ppt'
  sleep 105m
  :rightbelow vsplit
endfunction

function s:close_buffer_and_shrink_window()
  :q
  :silent execute '!i3-msg resize shrink width 10 px or 10 ppt'
endfunction

noremap <silent> <c-w> :call <SID>close_buffer_and_shrink_window()<Enter>
nnoremap <leader>v :call <SID>vsplit_and_grow_window()<Enter>

