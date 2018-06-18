atom.commands.add 'atom-text-editor',
  # Add command for toogling fold
  'editor:toggle-current-row-folding': (event) ->
    editor = @getModel()
    bufferRow = editor.bufferPositionForScreenPosition(editor.getCursorScreenPosition()).row

    if editor.isFoldedAtBufferRow(bufferRow)
      editor.unfoldBufferRow(bufferRow)
    else
      editor.foldBufferRow(bufferRow)

  # Add a command that folds everything except the current buffer row
  'editor:fold-all-except-current': (event) ->
    editor = @getModel()
    bufferRow = editor.bufferPositionForScreenPosition(editor.getCursorScreenPosition()).row

    editor.foldAll()
    editor.unfoldBufferRow(bufferRow)
