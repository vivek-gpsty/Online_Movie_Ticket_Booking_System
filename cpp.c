import Amplify, {
  Auth,
  API,
  graphqlOperation,
  button
}
from 'aws-amplify';
import awsconfig from "./aws-exports.js"
import {
  listMovies,
  getMovie,
  getSlot,
  getUserByUsername,
  getVenue
} from './graphql/queries.js';
import {
  updateUser,
  updateSlot,
  createMovie,
  createVenue,
  deleteMovie,
  createSlot,
  updateVenue,
  updateMovie
} from './graphql/mutations.js';
Amplify.configure(awsconfig)
//login page start//
const loginButton =
  document.getElementById('Login') try {
    loginButton.addEventListener('click', (evd) => {
      doLogin()
    })
  }
catch (e) {}
async function doLogin() {
  const userName = document.getElementById('username').value
  const
    passWord = document.getElementById('password').value
  try {
    if (userName == "admin" &&
      passWord == "admin123") {
      const user = await
      Auth.signIn(userName, passWord);
      sessionStorage.setItem("usermail", userName)
      window.location.replace("./Admin_Home1.html")
    } else {
      const user = await Auth.signIn(userName, passWord);
      sessionStorage.setItem("usermail", userName)
      window.location.replace("./Home_1.html")
    }
  } catch (error) {
    console.log('error signing in',
      error);
    alert(error.message)
  }
}
//login page ends//
//home page
1 //try{
document.getElementById("home_1").onload = function () {
  console.log("Home1 : Load")
  fetchData()
}
}
catch (err) {}
async function fetchData() {
  const mData = await API.graphql(graphqlOperation(listMovies))
  const Dat =
    mData.data.listMovies
  console.log("Data
    fetched ",Dat)
    let classArr = ["Rectangle_70", "Rectangle_74"]
    let
      classArr2 = ["Rectangle_76", "Rectangle_79"]
    let
      classArr3 = ["Rectangle_77", "Rectangle_78"]
    let idArr = ["Book ", "Book_"]
    for (let i = 0; i < 2; i++) {
      let image =
        document.createElement("img")
      image.className = classArr[i]
      image.src = Dat.items[i].imageURL
      let name =
        document.createElement("div")
      name.className = classArr2[i]
      let h1 = document.createElement("h1")
      h1.textContent = "Name:
      "+Dat.items[i].name let h2 =
      document.createElement("h1")
      h2.textContent = "Rating:
      "+Dat.items[i].ratingsname.append(h1)
      name.append(h2)
      let b =
        document.createElement("button")
      b.id = idArr[i]
      b.onclick = function () {
        sessionStorage.setItem("MovID", Dat.items[i].id)
      }
      let s =
        console.log("SelectedMovie:", Dat.items[i].id)
      window.location.assign("./BOOK.html")
      document.createElement("span")
      s.textContent = "Book"
      b.append(s)
      let de = document.createElement("div")
      de.className = classArr3[i]
      let hh1 =
        document.createElement("h1")
      hh1.textContent = "Description:"
      let hh2 =
        document.createElement("h2")
      hh2.textContent = Dat.items[i].desc
      de.append(hh1)
      de.append(hh2)
      document.getElementById("Ins_1").append(imag e)
      document.getElementById("Ins_1").append(nam e) document.getElementById("Ins_1").append(b)
      document.getElementById("Ins_1").append(de)
    }
  }
  //home page1 Done!//
  //booking
  page //try{
  document.getElementById("book_page").onload = function () {
    console.log("Booking page : Load")
    fetchMovie()
  }
}
catch (err) {}
var sDat =
  null;
async function fetchMovie() {
    var movid =
      sessionStorage.getItem("MovID")
    movid.toString()
    console.log("stored id:", movid)
    var movDat = await API.graphql(graphqlOperation(getMovie, {
      id: movid
    }));
    var Dat = movDat.data.getMovie
    let img = Dat.imageURL
    console.log("fetcched movie
        daa: ",Dat)
        //to show venues//
        const ven =
          Dat.venues.itemsvar l =
          null;
        var boxArr = ["Rectangle_57", "Rectangle_58", "Rectangle_59"];
        let
          z = document.createElement("img")
        z.className = "Rectangle_19"
        z.src = img document.getElementById("book_page").append(z) console.log("length of venue", ven.length) var i = 0;
        if (ven.length == 0)
          alert("It appears that you have no movies
            nearby ")else
            for (i = 0; i < ven.length; i++) {
              let parent =
                document.createElement("button")
              parent.id = ven[i].id
              parent.id2 = i
              parent.className =
                boxArr[i]
              parent.style = "background-color:
              #ffffff;
              "let t =
              document.createElement("h1")
              t.textContent = ven[i].name
              let k =
                document.createElement("h2")
              k.textContent = ven[i].location
              parent.onclick = async function () {
                console.log("data", ven[parent.id2])
                sessionStorage.setItem("venName", t.textContent)
                sessionStorage.setItem("venID", parent.id)
                fetchSlots(ven[parent.id2])
              }
              parent.append(t);
              parent.append(
                k);
              document.getElementById("venue_slot").append(parent)
            }
          }
        async function fetchSlots(rec) {
          let ro = rec.slots.items
          var boxArr2 = ["Rectangle_60", "Rectangle_61", "Rectangle_62", "Rectangle_63", "Rectangle_64"]
          if (ro.length == 0)
            alert("It appears that the movie has no
              slots ")else
              for (let i = 0; i < ro.length; i++) {
                let parent =
                  document.createElement("button")
                parent.id = ro[i].id
                parent.id2 = i
                parent.className =
                  boxArr2[i]
                parent.style = "background-color:
                #ffffff;
                "let t =
                document.createElement("h1")
                t.textContent = ro[i].time
                parent.onclick = async function () {
                  console.log("data", ro[parent.id2])
                  sessionStorage.setItem("Stiming", t.textContent)
                  sessionStorage.setItem("SID", ro[i].id)
                  fetchSeats(ro[parent.id2])
                }
                parent.append(t);
                document.getElementById("insSlot").append(pare nt)
              }
            }
          async function
          fetchSeats(recv2) {
            let s =
              recv2.seats
            let sArr = ["Rectangle_21", "Rectangle_36", "Rectangle_35", "Rectangle_34", "Rectangle_33",
              "Rectangle_33", "Rectangle_32", "Rectangle_31", "Rectangle_30", "Rectangle_29", "Rectangle
              _28 ","
              Rectangle_27 ",
              "Rectangle_26", "Rectangle_25", "Rectangle_24", "Rectangle_23", "Rectangle_22", "Rectangle
              _44 ",
              "Rectangle_43", "Rectangle_42", "Rectangle_41",
              "Rectangle_40", "Rectangle_39", "Rectangle_38",
              "Rectangle_37", "Rectangle_45", "Rectangle_46", "Rectangle_47", "Rectangle_48", "Rectangle
              _49 ",
              "Rectangle_50", "Rectangle_51", "Rectangle_52"
            ]
            let nArr = ["A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9",
              "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9",
              "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9",
              "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9"
            ]
            let setx = new Set();
            var Vid =
              sessionStorage.getItem("venID")
            Vid.toString()
            console.log("stored Venue id:", Vid)
            var Sid =
              sessionStorage.getItem("SID")
            Sid.toString()
            console.log("stored Slot id:", Sid)
            var VDat = await API.graphql(graphqlOperation(getSlot, {
              id: Sid
            }));
            var Dat = VDat.data.getSlot
            for (var i = 0; i < s.length; i++) {
              let parent =
                document.createElement("button")
              parent.id = i;
              parent.className =
                sArr[i]
              if (Dat.seats[i] == 0) {
                parent.style = "background-color:
                #ffffff;
                "parent.disabled =false
              } else {
                parent.style = "background-color:
                #f44336;
                "parent.disabled =true
              }
              parent.textContent = nArr[i];
              parent.onclick = async

              function () {
                if (!setx.has(nArr[parent.id])) {
                  selectedSeats.push(nArr[parent.id])
                  setx.add(nArr[parent.id])
                  SSn.push(parseInt(parent.id))
                }
                sessionStorage.setItem("SN", selectedSeats);
                displayStats()
              }
              document.getElementById("inSeats").append(parent)
            }
            async function displayStats() {
              console.log("selected seats:", selectedSeats, "|| volume:", selectedSeats.length)
              console.log("SSn:", SSn)
              let N =
                document.createElement("div")
              N.className = "Rectangle_56"
              let c1 =
                document.createElement("h2")
              c1.textContent =
                selectedSeats.length
              N.appendChild(c1)
              let parent2 =
                document.createElement("div")
              parent2.className = "Rectangle_55"
              let c2 =
                document.createElement("h2")
              c2.textContent = selectedSeats;
              parent2.appendChild(c2)
              if (document.getElementById("inNos").childElementCount != 0) {
                document.getElementById("inNos").removeChild(document.getElementById("inNos")
                  .firstC hild)
                document.getElementById("inPos").removeChild(document.getElementById("inPos")
                  .firstChild)
              }
              document.getElementById("inNos").append(N)
              document.getElementById("inPos").append(parent2)
            }
          }
          try {
            document.getElementById("Rectangle_65").onclick = function () {
              let le = selectedSeats.length
              if (le == 0)
                alert("It appers that you have not selected any
                  seats ")else{
                  sessionStorage.setItem("items", le) sessionStorage.setItem("seats", JSON.stringify(S Sn)) let x = sessionStorage.getItem("MovID")
                  let o =
                    sessionStorage.getItem("SN") let
                      str = x + ">" + y + ">" + z + ">" + o
                  console.log("mute string", str) sessionStorage.setItem("movieB",
                    str) window.location.assign("./Payment_Form.html")
                }
            }
          } catch (e) {}
          try {
            document.getElementById("_Back_gn").onclick = function () {
              selectedSeats = null;
              window.history.back()
            }
          } catch (e) {}
          var selectedSeats = []
          var SSn = []
          //booking page done//
          //payment
          page //try{
          document.getElementById("payment_page").onload = function () {
            console.log("Payment page : Load")
            fetchPrice()
          }
        }
        catch (err) {}
        async function fetchPrice() {
            console.log("inside payment page")
            console.log("sel
              array ",selectedSeats)
              console.log("selected
                seats ",parseInt(vol))let cost = 10
                let price = cost * vol
                let prit =
                  document.createElement("div") prit.id = "_546"
                prit.textContent = "$" + String(price); document.getElementById("cost").append(prit)
              }
              try {
                document.getElementById("button_proc").onclick = async function () {
                  console.log("Procede [pressed]")
                  alert("succefully booked:");
                  let z = sessionStorage.getItem("movieB")
                  const em2 = sessionStorage.getItem("usermail")
                  const em3 = JSON.parse(sessionStorage.getItem("seats"))
                  console.log("Seats", em3)
                  console.log("fetched sessstor", em2)
                  var Sid =
                    sessionStorage.getItem("SID")
                  Sid.toString()
                  console.log("stored Slot id:", Sid)
                  var VDat = await API.graphql(graphqlOperation(getSlot, {
                    id: Sid
                  }));
                  var Dat = VDat.data.getSlot
                  for (var
                      j = 0; j < em3.length; j++) {
                    Dat.seats[em3[j]] = 1
                  }
                  await API.graphql(graphqlOperation(updateSlot, {
                    input: {
                      id: Sid,
                      seats: Dat.seats
                    }
                  })) var usrDat = await
                  API.graphql(graphqlOperation(getUserByUsername, {
                    username: em2
                  }));
                  usrDat.data.getUserByUsername.history.unshif
                  t(z) let uidx =
                    usrDat.data.getUserByUsername.id
                  let ush = usrDat.data.getUserByUsername.history
                  await API.graphql(graphqlOperation(updateUser, {
                    input: {
                      id: uidx,
                      history: ush
                    }
                  }))
                  window.location.replace("./Booking_confirm.html")
                }
              } catch (err) {}
              //payment page done
              //managebooking
              page //try{
              document.getElementById("manage_b").onload = function () {
                console.log("Management Page : Load")
                fetchHistory()
              }
            }
            catch (err) {
              async function fetchHistory() {
                  const em1 =
                    sessionStorage.getItem("usermail")
                  console.log("fetched sessstor", em1)
                  var usrDat = await API.graphql(graphqlOperation(getUserByUsername, {
                    username: em1
                  }));
                  var Dat = usrDat.data.getUserByUsername.history
                  console.log("User
                    dat: ",usrDat)
                    console.log("userdata", Dat) var movD =
                      Dat[0].split(">") var moid =
                        movD[0]
                    var movDat = await API.graphql(graphqlOperation(getMovie, {
                      id: moid
                    }));
                    var Datm = movDat.data.getMovie
                    console.log("Moviedata", Datm) let image =
                      document.createElement("img")
                    image.className = "Rectangle_73"
                    image.src = Datm.imageURL
                    let name =
                      document.createElement("div")
                    name.className = "Rectangle_82"
                    let h1 =
                      document.createElement("h1")
                    h1.textContent =
                    "Name:" + Datm.name
                    let h2 =
                      document.createElement("h2")
                    h2.textContent = "Location:" + movD[1] + ", Time:" +
                    movD[2]
                    let h3 = document.createElement("h2")
                    name.append(h 1) name.append(h 2) name.append(h 3) let b =
                      document.createElement("button")
                    b.id = "CANCEL_"
                    b.onclick = async function () {
                      if (confirm("Do you really want to cancel the ticket, It can't be
                          undone ")){let uid = usrDat.data.getUserByUsername.id
                          usrDat.data.getUserByUsername.history.shift() let uhm = usrDat.data.getUserByUsername.history
                          // let ar = []
                          // ar.push(String(uhm))
                          console.log("uid:", uid, "history:", uhm) await API.graphql(graphqlOperation(updateUser, {
                            input: {
                              id: uid,
                              history: uhm
                            }
                          })) window.location.reload() console.log("Cancled. Refunded!!")
                        }
                        else {
                          alert("Not canceled")
                        }
                      }
                      let s =
                        document.createElement("span")
                      s.textContent = "Cancel "
                      b.append(s)
                      let de =
                        document.createElement("div")
                      de.className = "Rectangle_83"
                      let hh1 =
                        document.createElement("h1")
                      hh1.textContent = "Description:"
                      let hh2 =
                        document.createElement("h2")
                      hh2.textContent = Datm.desc
                      de.append(hh1)
                      de.append(hh2)
                      document.getElementById("mang").append(imag e)
                      document.getElementById("mang").append(nam e) document.getElementById("mang").append(b)
                      document.getElementById("mang").append(de)
                    }
                    try {
                      document.getElementById("CANCEL_").onclick = function () {
                        console.log("Cancled Page : Load")
                      }
                    } catch (e) {}
                    const lgm =
                      document.getElementById('Logout_cv') try {
                        lgm.addEventListener('click', (evd) => {
                          Auth.signOut();
                          sessionStorage.clear()
                          window.location.replace("./login.html")
                        })
                      }
                    catch (e) {}
                    const lg1 =
                      document.getElementById('Logout') try {
                        lg1.addEventListener('click', (evd) => {
                          Auth.signOut();
                          sessionStorage.clear()
                          window.location.replace("./login.html")
                        })
                      }
                    catch (e) {}
                    const lg2 =
                      document.getElementById('Logout_d') try {
                        lg2.addEventListener('click', (evd) => {
                          Auth.signOut();
                          sessionStorage.clear()
                          window.location.replace("./login.html")
                        })
                      }
                    catch (e) {}
                    //manage page done//
                    //Admin home1
                    start //try{
                    document.getElementById("admin_home_1").onload = function () {
                      console.log("Admin_Home1 : Load")
                      fetchData1()
                    }
                  }
                  catch (err) {}
                  async function fetchData1() {
                    const mData = await
                    API.graphql(graphqlOperation(listMovies)) const Dat =
                      mData.data.listMovies
                    console.log("Data fetched", Dat)
                    let classArr = ["Rectangle_71_mg", "Rectangle_72_mh"]
                    let
                      classArr2 = ["Rectangle_80_mi", "Rectangle_81_mj"]
                    let classArr3 = ["Rectangle_84_mk", "Rectangle_85_ml"]
                    let idArr = ["Rectangle_121_mo", "Rectangle_123"]
                    let delArr = ["Rectangle_122_mq", "Rectangle_124"]
                    for (let i = 0; i < 2; i++) {
                      let image =
                        document.createElement("img")
                      image.className = classArr[i];
                      image.src = Dat.items[i].imageURL
                      let name =
                        document.createElement("div")
                      name.className = classArr2[i]
                      let h1 = document.createElement("h1")
                      h1.textContent = "Name:
                      "+Dat.items[i].name let h2 =
                      document.createElement("h2")
                      h2.textContent = "Rating:
                      "+Dat.items[i].ratingsname.append(h1)
                      name.append(h2)
                      // update button here
                      let b =
                        document.createElement("button") let
                          s = document.createElement("span")
                      b.className = idArr[i]
                      b.textContent =
                        "Update>"
                      b.onclick =
                        function () {
                          sessionStorage.setItem("MovID", Dat.items[i].id)
                          console.log("SelectedMovie:", Dat.items[i].id)
                          window.location.assign("./Update.html")
                        }
                      // delete button here
                      let m =
                        document.createElement("button")
                      m.className = delArr[i]
                      m.id2 = Dat.items[i].id
                      m.textContent = "Delete"
                      m.onclick = async function () {
                        sessionStorage.setItem("MovID", Dat.items[i].id)
                        console.log("SelectedMovie:", Dat.items[i].id)
                        console.log("Delete pressed")
                        await API.graphql(graphqlOperation(deleteMovie, {
                          input: {
                            id: m.id2
                          }
                        }))
                        window.location.reload()
                      }
                      let de =
                        document.createElement("div")
                      de.className = classArr3[i]
                      let hh1 =
                        document.createElement("h1")
                      hh1.textContent = "Description:"
                      let hh2 =
                        document.createElement("h2")
                      hh2.textContent = Dat.items[i].desc
                      de.append(hh1)
                      de.append(hh2)
                      document.getElementById("Admin_ins").append(image)
                      document.getElementById("Admin_ins").append(name)
                      document.getElementById("Admin_ins").append(m)
                      document.getElementById("Admin_ins").append(b)
                      document.getElementById("Admin_ins").append(de)
                    }
                  }
                  //admin_home 1 finished
                  // update page
                  starttry {
                    document.getElementById("update_").onload =
                      function () {
                        console.log("Update page : Load")
                        fetchMovieUpdate()
                      }
                  } catch (err) {}
                  var sDat =
                    null;
                  async function fetchMovieUpdate() {
                      var movid =
                        sessionStorage.getItem("MovID")
                      movid.toString()
                      console.log("stored id:", movid)
                      var movDat = await API.graphql(graphqlOperation(getMovie, {
                        id: movid
                      }));
                      var Dat = movDat.data.getMovie
                      sessionStorage.setItem("movdata", JSON.stringify(Dat))
                      console.log("fetcched movie daa:", Dat)
                      //to show venues//
                      const ven = Dat.venues.items
                      var boxArr = ["Rectangle_57_m", "Rectangle_58_na", "Rectangle_59_nb"];
                      console.log("length of
                          venue ",ven.length) let part =
                          document.createElement("input") part.className = "Rectangle_117_nl"
                          part.placeholder = Dat.name part.type = "text"
                          part.id =
                          "movieName"
                          let part2 =
                            document.createElement("input")
                          part2.className =
                          "Rectangle_118_nm"
                          part2.placeholder = Dat.desc part2.type = "text"
                          part2.id =
                          "DescMovie"
                          let part3 =
                            document.createElement("input")
                          part3.className = "Rectangle_19_m"
                          part3.placeholder = Dat.imageURL part3.type = "text"
                          part3.id = "ImgMovie"
                          if (ven.length == 0)
                            alert("It appears that you have no movies
                              nearby ")else
                              for (var i = 0; i < 3; i++) {
                                try {
                                  let name =
                                    document.createElement("input")
                                  name.className = boxArr[i]
                                  name.type = "text"
                                  name.id2 = ven[i].id
                                  name.id = "venue" + (i + 1)
                                  name.placeholder = ven[i].name + ":" + ven[i].location
                                  //
                                  document.getElementById("venue_slot").append(pare nt) //
                                  document.getElementById("Update_ins2").append(na me)
                                  document.getElementById("Update_ins2").append(part)
                                  document.getElementById("Update_ins2").append(part2)
                                  document.getElementById("Update_ins2").append(part3)
                                } catch (e) {}
                              }
                              let sel1 =
                                document.createElement("button")
                              sel1.id = "Submit_Venue"
                              sel1.textContent = "Submit
                              Venue "sel1.onclick = async
                              function () {
                                let vard =
                                  JSON.parse(sessionStorage.getItem("movdata")) let
                                    ven1 = ""
                                let ven2 = ""
                                let ven3 = ""
                                try {
                                  ven1 = document.getElementById("venue1").value
                                } catch (r) {}
                                try {
                                  ven2 = document.getElementById("venue2").value
                                } catch (r) {}
                                try {
                                  ven3 = document.getElementById("venue3").value
                                } catch (r) {}
                                console.log("Pressed", ven1, ven2, ven3)
                                if (ven1 != "" && ven2 == "") {
                                  if (ven3 == "") {
                                    fetchSlotsUpdate(ven[0].id, ven1)
                                    console.log("ven1 only", ven[0].id, ven1)
                                  }
                                }
                                if (ven1 == "" && ven2 != "") {
                                  if (ven3 == "") {
                                    fetchSlotsUpdate(ven[1].id, ven2)
                                    console.log("ven2 only", ven[1].id, ven2)
                                  }
                                }
                                if (ven1 == "" && ven2 == "") {
                                  if (ven3 != "") {
                                    fetchSlotsUpdate(ven[2].id, ven3)
                                    console.log("ven3 only", ven[2].id, ven3)
                                  }
                                }
                              }
                              document.getElementById("Update").append(sel1)
                            }
                          async function fetchSlotsUpdate(venid, stdata) {
                            let [namee, locatione] = stdata.split(":")
                            console.log("data sent in: ", namee, locatione)
                            const venD = await await API.graphql(graphqlOperation(getVenue, {
                              id: venid
                            }));
                            console.log("slots data:", venD.data.getVenue.slots.items)
                            var boxArr2 = ["Rectangle_60_nc", "Rectangle_61_nd", "Rectangle_62_ne", "Rectangle_63_nf", "Rect
                              angle_ 64_n g "]
                              let ro =
                                venD.data.getVenue.slots.items
                              for (let i = 0; i < ro.length; i++) {
                                try {
                                  let name =
                                    document.createElement("input")
                                  name.className = boxArr2[i]
                                  name.type = "text"
                                  name.placeholder =
                                    ro[i].timename.id =
                                    "slot" + (i + 1) name.id2 =
                                    ro[i].id
                                  //document.getElementById("Update_ins2").append(name)//
                                  document.getElementById("Update_ins2").append(name)
                                } catch (e) {}
                              }
                              //slots button
                              let sel2 =
                                document.createElement("button")
                              sel2.id = "Submit_Slots"
                              sel2.textContent = "Procede"
                              sel2.onclick = async function () {
                                console.log("slots clicked")
                                let sl1 = ""
                                let sl2 = ""
                                let sl3 = ""
                                let sl4 = ""
                                let sl5 = ""
                                try {
                                  sl1 = document.getElementById("slot1").value
                                } catch (r) {}
                                try {
                                  sl2 = document.getElementById("slot2").value
                                } catch (r) {}
                                try {
                                  sl3 = document.getElementById("slot3").value
                                } catch (r) {}
                                try {
                                  sl4 = document.getElementById("slot4").value
                                } catch (r) {}
                                try {
                                  sl5 = document.getElementById("slot5").value
                                } catch (r) {}
                                var sln = ""
                                var slv = ""
                                if (sl1 != "" && sl2 == "" && sl3 == "" && sl4 == "" && sl5 == "") {
                                  sln = 0
                                  slv = sl1
                                }
                                if (sl1 == "" && sl2 != "" && sl3 == "" && sl4 == "" && sl5 == "") {
                                  sln = 1
                                  slv = sl2
                                }
                                if (sl1 == "" && sl2 == "" && sl3 != "" && sl4 == "" && sl5 == "") {
                                  sln = 2
                                  slv = sl3
                                }
                                if (sl1 == "" && sl2 == "" && sl3 == "" && sl4 != "" && sl5 == "") {
                                  sln = 3
                                  slv = sl4
                                }
                                if (sl1 == "" && sl2 == "" && sl3 == "" && sl4 == "" && sl5 != "") {
                                  sln = 4
                                  slv = sl5
                                }
                                let nam = ""
                                let
                                  nameA = ""
                                let
                                  ratinga = ""
                                let
                                  de = ""
                                let inh = ""
                                try {
                                  nam = document.getElementById("movieName").value
                                  nameA = String(nam.split(">")[0])
                                  ratinga = String(nam.split(">")[1])
                                } catch (e) {}
                                try {
                                  de = document.getElementById("DescMovie").value
                                } catch (e) {}
                                try {
                                  inh = document.getElementById("ImgMovie").value
                                } catch (e) {}
                                await
                                API.graphql(graphqlOperation(updateVenue, {
                                  input: {
                                    id: venid,
                                    name: namee,
                                    location: locatione,
                                  }
                                }))
                                await API.graphql(graphqlOperation(updateSlot, {
                                  input: {
                                    id: ro[sln].id,
                                    time: slv,
                                    seats: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                      0
                                    ],
                                  }
                                }))
                                var movid =
                                  sessionStorage.getItem("MovID")
                                movid.toString()
                                console.log("stored id:", movid)
                                console.log("new name:", nameA, "new ratinf:", ratinga, "new desc:", de)
                                API.graphql(graphqlOperation(updateMovie, {
                                  input: {
                                    id: movid,
                                    name: nameA,
                                    ratings: rating
                                    a,
                                    desc: de,
                                    imageURL: in
                                      h,
                                  }
                                }))
                                window.location.assign('./Update_Complete.html')
                              }
                              document.getElementById("Update").append(sel2)
                            }
                            try {
                              document.getElementById("_Back_gn").onclick = function () {
                                selectedSeats = null;
                                window.history.back()
                              }
                            } catch (e) {}
                            // add movie
                            starttry {
                              document.getElementById("add_movie").onload = function () {
                                console.log("add page : Load")
                                fetchaddmoviepage()
                              }
                            } catch (err) {}
                            async function fetchaddmoviepage() {
                              let but = document.createElement("button")
                              but.id = "Proceed i";
                              but.textContent = "Proceed"
                              but.onclick = async function addMovie() {
                                const venue1 =
                                  document.getElementById('venue1').valuevar
                                movieN = document.getElementById('movieN').value
                                const
                                  MDesc = document.getElementById('MDesc').value
                                const url = document.getElementById('url').value
                                //after fetching data
                                console.log("venue1:", venue1)
                                const slot1 = document.getElementById('slot1').value
                                console.log("slot1:", slot1)
                                var movieid = await API.graphql(graphqlOperation(createMovie, {
                                  input: {
                                    name: movieN.split(">")[0],
                                    ratings: movieN.split(">")[1],
                                    desc: MDesc,
                                    imageURL: url
                                  }
                                }))
                                console.log("Created moviei d", )
                                var venueid = await
                                API.graphql(graphqlOperation(createVenue, {
                                  input: {
                                    venueMoviesId: movieid.data.createMovie.id,
                                    location: venue1.split(":")[0],
                                    name: venue1.split(":")[1],
                                  }
                                }))
                                var slotid = await API.graphql(graphqlOperation(createSlot, {
                                  input: {
                                    slotVenueId: venueid.data.createVenue.id,
                                    time: slot1,
                                    seats: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                      0
                                    ]
                                  }
                                }))
                                alert("Movie Succesfully Created")
                              }
                              document.getElementById("prc_b").append(but)
                            }
                          }
                          SCHEMA.GRAPHQL type User {
                            id: ID!
                              name: String!
                              username: String!email: String!address: String!history: [String]
                            upcoming: [String]
                            createdAt: AWSDateTime!
                              updatedAt: AWSDateTime!
                          }
                          type Movie {
                            id: ID!
                              name: String!
                              ratings: String
                            desc: String
                            imageURL: String
                            venues(filter: ModelVenueFilterInput, sortDirection: ModelSortDirection, limit: Int,
                              nextToken: String): ModelVenueConnection
                            createdAt: AWSDateTime!
                              updatedAt: AWSDateTime!
                          }
                          type Venue {
                            id: ID!
                              slots(filter: ModelSlotFilterInput, sortDirection: ModelSortDirection, limit: Int, nextToken:
                                String): ModelSlotConnection
                            name: String!
                              location: String!seats: [Int] movies: Movie
                            createdAt: AWSDateTime!
                              updatedAt: AWSDateTime!
                          }
                          type Slot {
                            id: ID!
                              seats: [Int]
                            time: String!
                              venue: Venue
                            createdAt: AWSDateTime!
                              updatedAt: AWSDateTime!
                          }
                          type Query {
                            getUserByUsername(username: String!):
                              UsergetVenueByName(name: String!):
                              Venue getMovieByName(name: String!):
                              Movie getUser(id: ID!): User
                            listUsers(filter: ModelUserFilterInput, limit: Int, nextToken: String): ModelUserConnection
                            getMovie(id: ID!): Movie
                            listMovies(filter: ModelMovieFilterInput, limit: Int, nextToken: String):
                              ModelMovieConnection
                            getVenue(id: ID!): Venue
                            listVenues(filter: ModelVenueFilterInput, limit: Int, nextToken: String):
                              ModelVenueConnection
                            getSlot(id: ID!): Slot
                            listSlots(filter: ModelSlotFilterInput, limit: Int, nextToken: String): ModelSlotConnection
                          }
                          enum ModelSortDirection {
                            ASC
                            DESC
                          }
                          type ModelUserConnection {
                            items: [User]
                            nextToken: String
                          }
                          input ModelStringInput {
                            ne: String
                            eq: Stringle: Stringlt: String
                            ge: String
                            gt: String
                            contains: String
                            notContains: String
                            between: [String]
                            beginsWith: String
                            attributeExists: Boolean
                            attributeType: ModelAttributeTypessize: ModelSizeInput
                          }
                          input ModelIDInput {
                            ne: ID
                            eq: IDle: ID lt: ID
                            ge: IDgt: ID
                            contains: ID
                            notContains: ID
                            between: [ID]
                            beginsWith: ID
                            attributeExists: Boolean
                            attributeType: ModelAttributeTypessize: ModelSizeInput
                          }
                          input ModelIntInput {
                            ne: Int
                            eq: Int le: Int lt: Int
                            ge: Intgt: Int
                            between: [Int]
                            attributeExists: Boolean
                            attributeType: ModelAttributeTypes
                          }
                          input ModelFloatInput {
                            ne: Float
                            eq: Floatle: Floatlt: Float
                            ge: Floatgt: Float
                            between: [Float]
                            attributeExists: Boolean
                            attributeType: ModelAttributeTypes
                          }
                          input ModelBooleanInput {
                            ne: Boolean
                            eq: Boolean
                            attributeExists: Boolean
                            attributeType: ModelAttributeTypes
                          }
                          input ModelSizeInput {
                            ne: Int
                            eq: Intle: Intlt: Int
                            ge: Int
                            gt: Int
                            between: [Int]
                          }
                          input ModelUserFilterInput {
                            id: ModelIDInput
                            name: ModelStringInput
                            username: ModelStringInputemail: ModelStringInput address: ModelStringInput history: ModelStringInput
                            upcoming: ModelStringInputand: [ModelUserFilterInput] or: [ModelUserFilterInput]
                            not: ModelUserFilterInput
                          }
                          enum ModelAttributeTypes {
                            binary
                            binaryS
                            etbool
                            list
                            map
                            numbe
                            r
                            numberS
                            etstring
                            stringSet
                            _null
                          }
                          input CreateUserInput {
                            id: ID
                            name: String!
                              username: String!email: String!address: String!history: [String]
                            upcoming: [String]
                          }
                          input UpdateUserInput {
                            id: ID!
                              name: String
                            username: String
                            email: String
                            address: String
                            history: [String]
                            upcoming: [String]
                          }
                          input DeleteUserInput {
                            id: ID
                          }
                          type Mutation {
                            createUser(input: CreateUserInput!, condition: ModelUserConditionInput): User
                            updateUser(input: UpdateUserInput!, condition: ModelUserConditionInput): User
                            deleteUser(input: DeleteUserInput!, condition: ModelUserConditionInput): User
                            createMovie(input: CreateMovieInput!, condition: ModelMovieConditionInput):
                              Movie updateMovie(input: UpdateMovieInput!, condition:
                                ModelMovieConditionInput): MoviedeleteMovie(input: DeleteMovieInput!,
                                condition: ModelMovieConditionInput): Movie createVenue(input:
                                CreateVenueInput!, condition: ModelVenueConditionInput): Venue
                            updateVenue(input: UpdateVenueInput!, condition: ModelVenueConditionInput):
                              VenuedeleteVenue(input: DeleteVenueInput!, condition:
                                ModelVenueConditionInput): Venue
                            createSlot(input: CreateSlotInput!, condition: ModelSlotConditionInput): Slot
                            updateSlot(input: UpdateSlotInput!, condition: ModelSlotConditionInput): Slot
                            deleteSlot(input: DeleteSlotInput!, condition: ModelSlotConditionInput): Slot
                          }
                          input ModelUserConditionInput {
                            name: ModelStringInput
                            username: ModelStringInput
                            email: ModelStringInput
                            address: ModelStringInput
                            history: ModelStringInput
                            upcoming: ModelStringInput
                            and: [ModelUserConditionInput] or: [ModelUserConditionInput]
                            not: ModelUserConditionInput
                          }
                          type Subscription {
                            onCreateUser: User @aws_subscribe(mutations: ["createUser"])
                            onUpdateUser: User @aws_subscribe(mutations: ["updateUser"]) onDeleteUser: User
                            @aws_subscribe(mutations: ["deleteUser"]) onCreateMovie: Movie @aws_subscribe(mutations: ["createMovie"])
                            onUpdateMovie: Movie @aws_subscribe(mutations: ["updateMovie"]) onDeleteMovie: Movie
                            @aws_subscribe(mutations: ["deleteMovie"]) onCreateVenue: Venue @aws_subscribe(mutations: ["createVenue"])
                            onUpdateVenue: Venue @aws_subscribe(mutations: ["updateVenue"]) onDeleteVenue: Venue
                            @aws_subscribe(mutations: ["deleteVenue"]) onCreateSlot: Slot
                            @aws_subscribe(mutations: ["createSlot"]) onUpdateSlot: Slot
                            @aws_subscribe(mutations: ["updateSlot"]) onDeleteSlot: Slot
                            @aws_subscribe(mutations: ["deleteSlot"])
                          }
                          type ModelMovieConnection {
                            items: [Movie]
                            nextToken: String
                          }
                          input ModelMovieFilterInput {
                            id: ModelIDInput
                            name: ModelStringInput
                            ratings: ModelStringInput
                            desc: ModelStringInput
                            imageURL: ModelStringInputand: [ModelMovieFilterInput] or: [ModelMovieFilterInput]
                            not: ModelMovieFilterInput
                          }
                          input CreateMovieInput {
                            id: ID
                            name: String!
                              ratings: String
                            desc: String
                            imageURL: String
                          }
                          input UpdateMovieInput {
                            id: ID!
                              name: String
                            ratings: String
                            desc: String
                            imageURL: String
                          }
                          input DeleteMovieInput {
                            id: ID
                          }
                          input ModelMovieConditionInput {
                            name: ModelStringInput
                            ratings: ModelStringInput
                            desc: ModelStringInput
                            imageURL: ModelStringInput
                            and: [ModelMovieConditionInput] or: [ModelMovieConditionInput]
                            not: ModelMovieConditionInput
                          }
                          type ModelVenueConnection {
                            items: [Venue]
                            nextToken: String
                          }
                          input ModelVenueFilterInput {
                            id: ModelIDInput
                            name: ModelStringInput
                            location: ModelStringInputseats: ModelIntInput
                            and: [ModelVenueFilterInput] or: [ModelVenueFilterInput]
                            not: ModelVenueFilterInput
                          }
                          input CreateVenueInput {
                            id: ID
                            name: String!
                              location: String!seats: [Int]
                            venueMoviesId: ID
                          }
                          input UpdateVenueInput {
                            id: ID!
                              name: String
                            location: String
                            seats: [Int]
                            venueMoviesId: ID
                          }
                          input DeleteVenueInput {
                            id: ID
                          }
                          input ModelVenueConditionInput {
                            name: ModelStringInput
                            location: ModelStringInputseats: ModelIntInput
                            and: [ModelVenueConditionInput] or: [ModelVenueConditionInput]
                            not: ModelVenueConditionInput
                          }
                          type ModelSlotConnection {
                            items: [Slot]
                            nextToken: String
                          }
                          input ModelSlotFilterInput {
                            id: ModelIDInput
                            seats: ModelIntInput
                            time: ModelStringInput
                            and: [ModelSlotFilterInput]
                            or: [ModelSlot
                              FilterInput
                            ]
                            not: ModelSlot
                            FilterInput
                          }
                          input Create SlotInp ut {
                            id: ID
                            s
                            e
                            a
                            t
                            s: [I
                              n
                              t
                            ]
                            ti
                            m
                            e: S
                            tr
                            i
                            n
                            g!
                            sl
                            o
                            t
                            V
                            e
                            n
                            u
                            e
                            I
                            d: I
                            D
                          }
                          input Update SlotInp ut {
                            id: ID!
                              s
                            e
                            a
                            t
                            s: [In
                              t
                            ]
                            time: S
                            tring
                            sl otVenueId: I D
                          }
                          input Delete SlotInp ut {
                            id: ID
                          }
                          input ModelSlotCondi tionInput {
                            seats: ModelIntInput
                            time: ModelStringInput
                            and: [ModelSlotCond
                              itionInput
                            ] or: [ModelSlotCond
                              itionInput
                            ] not: ModelSlotCondi
                            tionInput
                          }