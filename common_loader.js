fetch("/common.html").then(r => r.text()).then(t => {
  document.head.innerHTML += t;
})