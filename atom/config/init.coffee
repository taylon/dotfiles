# Add command for toogling fold
atom.commands.add 'atom-text-editor',
  'editor:toggle-current-row-folding': (event) ->
    editor = @getModel()
    bufferRow = editor.bufferPositionForScreenPosition(editor.getCursorScreenPosition()).row

    if editor.isFoldedAtBufferRow(bufferRow)
      editor.unfoldBufferRow(bufferRow)
    else
      editor.foldBufferRow(bufferRow)
