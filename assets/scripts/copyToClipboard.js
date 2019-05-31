
const copyCodeElementToClipboard = className => {

  const str = document.getElementsByClassName(className)[0].firstChild.firstChild.innerText;
  copyToClipboard(str);
  showTooltip(2000);

};

const copyToClipboard = str => {

  const el = document.createElement('textarea');
  el.value = str;
  document.body.appendChild(el);
  el.select();
  document.execCommand('copy');
  document.body.removeChild(el);

};

const showTooltip = timeout => {

  const tooltip = document.getElementsByClassName('tooltip')[0];
  tooltip.style.display = 'inline-block';
  setTimeout(function() {
    tooltip.style.display = 'none';

  }, timeout);

};