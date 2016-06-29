let { extname } = require('path')
const { spawn } = require('child_process')
let { Inotify } = require('inotify')
let inotify = new Inotify()

const changeHandler = event => {
  let { mask } = event
  let filename = event.name
  if(
    mask &&
    // got modified
    Inotify.IN_MODIFY &&
    // is not a directory
    Inotify.IN_ISDIR &&
    // has fileending .c
    (extname(filename) === '.c')
    ) {

      console.log(`=> recompiling ${filename}`)
      let compilation = spawn('gcc', [filename])
      compilation.stderr.on('data', err => {
        console.log(err.toString())
      })
      compilation.on('close', exitCode => {
        if (!exitCode) {
          console.log(`=> compilation successful`)
          // TODO: hardcoded to a.out for now
          console.log(`trying to run ./a.out`)
          let execution = spawn('./a.out')
          execution.stdout.on('data', data => {
            console.log(data.toString())
          })
          execution.on('close', exitCode => {
            if (!exitCode) {
              console.log(`=> a.out execution successful`)
            }else {
              console.log(`=> a.out execution failed`)
            }
          })
        }else {
          console.log(`=> compilation failed`)
        }
      })
  }
}

let currentDir = {
  path: __dirname,
  // Todo: even recompiles when content was not changed
  watch_for: Inotify.IN_CLOSE_WRITE,
  callback: changeHandler
}

let watchDescriptor = inotify.addWatch(currentDir)
